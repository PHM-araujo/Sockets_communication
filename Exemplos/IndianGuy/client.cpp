#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

using namespace std;

int main(){
    /* ---------- INICIALIZACAO DAS VARIAVEIS ---------- */

    /*

        1. Client é um descritor de arquivo para armazena os  
        valores retornados pela socket system call e o accept 
        system call.

        2. portNum é para armazenar o numero da porta na qual 
        aceita as conexões 

        3. isExit é uma variavel bool a qual será usada para 
        finalizar o loop

        4. O cliente lê os caracteres da conexão socket em uma 
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

    */

    int client;
    int portNum = 1500; // NOTE that the port number is same for both client and server
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    char *ip = "127.0.0.1";

    struct sockaddr_in server_addr;

    client = socket(AF_INET, SOCK_STREAM, 0);

     /* ---------- ESTABELECENDO A CONEXAO SOCKET ----------*/
    /* --------------- socket() function ------------------*/

    if (client < 0) 
    {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }

    /*
        A função socket() cria uma noVa socket 
        Ela leva 3 argumentos

        a. AF_INET: domínio de endereço do socket
        b. SOCK_STREAM: Tipo de socket. Um fluxo de socket 
        no qual caracteres sao lidos em um fluxo continuo (TCP) 
        c. Third é um argumento protocolo: Deve ser sempre ser 
        zero. O sistema Operacional vai escolher o  mais apropriado

        Isso irá retornar um pequeno interiro e é usado para todas 
        as referncias da socket. Se chamada da socket falhar, ele 
        retornar -1  

    */

    cout << "\n=> Socket client has been created..." << endl;

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
    server_addr.sin_port = htons(portNum);

    /* ---------- CONNECTING THE SOCKET ---------- */
    /* ---------------- connect() ---------------- */

    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        cout << "=> Connection to the server port number: " << portNum << endl;

    /* 
        A funcao de conexao e chamada pelo clinte 
        para estabelecer uma conexao com o servidor. Ele aceita 
        tres argumentos, o descritor do arquivo do socket, o endereco
        do host no qual ele quer conectar (incluindo o numero da porta),
        e o tamanho do endereco 

        Essa funcao retorna 0 caso bem sucedida e -1 se falhar

        Note que o cliente precisa saber o numero da porta do sevidor
        mas seu proprio numero de porta  


    */

    cout << "=> Awaiting confirmation from the server..." << endl; //line 40
    recv(client, buffer, bufsize, 0);
    cout << "=> Connection confirmed, you are good to go...";

    cout << "\n\n=> Enter # to end the connection\n" << endl;

    // Uma vez que esse ponto e atindido, o cliente pode enviar uma msg

    do {
        cout << "Client: ";
        do {
            cin >> buffer;
            send(client, buffer, bufsize, 0);
            if (*buffer == '#') {
                send(client, buffer, bufsize, 0);
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != 42);

        cout << "Server: ";
        do {
            recv(client, buffer, bufsize, 0);
            cout << buffer << " ";
            if (*buffer == '#') {
                *buffer = '*';
                isExit = true;
            }

        } while (*buffer != 42);
        cout << endl;

    } while (!isExit);

    /* ---------------- CLOSE CALL ------------- */
    /* ----------------- close() --------------- */

    /*
    Uma vez que o servidor pressiona # para terminar a conexao,
    o loop ira interomper e sera fechadas a conenexoes socket
    do servidor e do cliente
    */

    cout << "\n=> Connection terminated.\nGoodbye...\n";

    close(client);
    return 0;
    
}


