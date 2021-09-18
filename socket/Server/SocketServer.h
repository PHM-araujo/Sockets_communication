#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

class SocketServer{

    private:
        int portNumber;
        struct sockaddr_in address;
        int socket_fd, newSocket, addrlen, opt;

    public:

        SocketServer();
        
        // Conecta o socket a porta 
        void conectPortSocket();

        // Liga a socket ao numero da porta e endereco presente na struct address 
        void bindSocket();

        // Coloca a socket em um modo passivo, onde ela espera o cliente se comunicar 
        void listenSocket();

        // Extrai a primeira conexao da fila de conexoes pendentes de espera e cria uma nova socket conectada 
        void acceptSocket();

        // Recebe a mensagem
        std::string readMessage();

};

#endif