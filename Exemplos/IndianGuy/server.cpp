#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main(){

    /* ---------- INICIALIZACAO DAS VARIAVEIS ---------- */

    /*

        1. Client/server são dois descritores de arquivos.
        Essas duas variaveis armazenam os valores retornados
        pela socket system call e o accept system call.

        2. portNum é para armazenar o numero da porta na qual 
        aceita as conexões 

        3. isExit é uma variavel bool a qual será usada para 
        finalizar o loop

        4. O server lê os caracteres da conexão socket em uma 
        variavel dinâmica (buffer)

        5. Um sockaddr_in é uma estrutura que contem um endereço
        de internet. Essa estrtura já esta definida em netnet/in.h, 
        então não é necessario declara-lo novamente 

        DEFINITION:

        struct sockaddr_in
        {
          short   sin_family;
          u_short sin_port;
          struct  in_addr sin_addr;
          char    sin_zero[8];
        }; 

        6. serv_addr irá conter os endereços do servidor

        7. soclen_t é um inteiro de temanho de até 32 bits 

    */



    int client, server;
    int portNum = 1500;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];

    struct  sockaddr_in server_addr;
    socklen_t size;

    // init socket 

    /* ---------- ESTABELECENDO A CONEXÃO DA SOCKET ----------*/
    /* --------------- socket() function ------------------*/

    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0){
        cout << "\nError estabilishing connection." << endl;
        exit(1);
    }

    /*
        A função socket() cria uma noca socket 
        Ele leva 3 argumentos

        a. AF_INET: domínio de endereço do socket
        b. SOCK_STREAM: Tipo de socket. Um fluxo de socket 
        no qual caracteres sao lidos em um fluxo continuo (TCP) 
        c. Third é um argumento protocolo: Deve ser sempre ser 
        zero. O sistema Operiacional vai escolher o  mais apropriado

        Isso irá retornar um pequeno interiro e é usado para todas 
        as referncias da socket. Se chamada da socket falhar, ele 
        retornar -1  

    */

    cout << "\n=>Server Socket connection created..." << endl;

    /*

        A variavel sever_addr é uma estrututra de sockaddr_in.
        sin_family contem um codigo para o andereco da familia.
        Ele deve ser sempre configurado a AF_INET

        INADDR_ANY contem o endereço de IP do host. Para o codigo
        do servidor, isso ira sempre ser o endreco de IP da maquina
        na qual o servidor esta funcionando

        htons() converte o numero da porta da ordem de bytes do host
        para um numero de porta na ordem de bytes a rede 

    */

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);


    /* ---------- BINDING THE SOCKET ---------- */
    /* ---------------- bind() ---------------- */


    if (bind(client, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        cout << "=> Error binding conection, yhe socket has already been estabilished..." << endl;
        exit(-1);
    }

    /*

    A chamada de sistema bind() conecta uma socket a 
    um endereço, nesse caso, o endereço do atual host e numero da porta 
    no qual o servidor ira funcionar. Ele leva tres argunentos, o 
    descritor do arquivo da socket. O segundo argumento é um ponteiro 
    para a estrutura do tipo sockaddr, isso deve ser convertido 
    para o tipo correto.  

    */

   size = sizeof(server_addr);
   cout << "=> looking for clients.." << endl;

    /* ------------- LISTENING CALL ------------- */
    /* ---------------- listen() ---------------- */

    listen(client, 1);

    /*

    A Chamada do sistema listen permite o processo  "escutar"
    na conexao da socket 

    O programa ira permanecer em estado repouso aqui se nao houver
    conexoes de entrada.

    O primeiro argumento e o descritor do arquivo socket, e o segundo e
    o tamanho o tamanho do numero de clientes (ex: o numero de conexoes
    que o server pode lidar enquanto o processo esta lidando com uma 
    conexao em particular. O tamanho maximo permitido pela maioria 
    dos sistemas e 5

    */

    /* ------------- ACCEPTING CLIENTS  ------------- */
    /* ----------------- listen() ------------------- */

    /*

        A chamada de sistema accept() faz o processo bloquear
        ate o cliente se conectar ao servidor. Entao, ele acordar
        o processo quando a conexao com o cliente foi estabelecida com
        sucesso. Ele retorna um novo descritor de arquivo, toda comunicao
        nessa conexao deve ser feita usando o novo descritor de arquivo. 
        O segundo argumento e uma referencia a um ponteiro ao endereco do
        cliente no outro lado da conexao, e o terceiro arqumento e o tamanho
        da estrutura 

    */

    int clientCount = 1;
    server = accept(client,(struct sockaddr *)&server_addr,&size);

    // Primeiro checa se e valido ou nao 
    if(server < 0){
        cout << "=> Error on accepting..." << endl;
        exit(1);
    }

    while(server > 0){
        strcpy(buffer, "=> Server connected...\n");
        send(server, buffer, bufsize, 0);
        cout << "=> Connected with the client #" << clientCount << ", you are good to go..." << endl;
        cout << "\n=> Enter # to end the connection\n" << endl;

        /*
            Note que nos apenas chegaremos a esse ponto apos um 
            cliente ter se conectado com sucesso ao nosso servidor.
            Isso le do socket. Note que o read() irá bloquear 
            ate haver algo para ler no socket, ex. apos o cliente 
            ter executado o send()

            Isso irá ler o numero total de caracteres no socket ou
            1024
        */

       cout << "Client: ";

       do{
           recv(server, buffer, bufsize, 0);
           cout << buffer << " ";
           if (*buffer == '#'){
               *buffer = '*';
                isExit = true;
           }
       }while(*buffer != '*');

       do{
           cout << "\nServer: ";

           do{
               cin >> buffer;
               send(server, buffer, bufsize, 0);

               if (*buffer == '#') {
                    send(server, buffer, bufsize, 0);
                    *buffer = '*';
                    isExit = true;
                }
           }while(*buffer != '*');

           cout << "Client: ";
           do{
               recv(server, buffer, bufsize, 0);
               cout << buffer << " ";
               if (*buffer == '#') {
                *buffer == '*';
                isExit = true;
               }
           } while (*buffer != '*');
       }while (!isExit);

       /*

            Uma vez que uma conexao foi estabelecida, ambas as 
            extremidade podem ler e gravar na conexao. Naturalmente, 
            tudo escrito pelo cliente sera lido pelo servidor e vice e 
            versa. 

       */

        /* ---------------- CLOSE CALL ------------- */
        /* ----------------- close() --------------- */

        /*
            Uma vez que o servidor pressiona # para terminar a conexao,
            o loop ira interomper e sera fechadas a conenexoes socket
            do servidor e do cliente
        */

       // inet_ntoa converte um pacote de dados em um IP, o qual foi pego do cliente
        cout << "\n\n=> Connection terminated with IP " << inet_ntoa(server_addr.sin_addr);
        close(server);
        cout << "\nGoodbye..." << endl;
        isExit = false;
        exit(1);
    }

    close(client);
    return 0; 
    
}