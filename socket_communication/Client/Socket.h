#ifndef SOCKET_H
#define SOCKET_H

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

class Socket{

    private:
        int portNumber;
        struct sockaddr_in address;
        std::string buffer;
        int socket_fd, newSocket, addrlen;

    public:

        Socket();

        // Liga a socket ao numero da porta e endereco presente na struct address 
        bool bindSocket();

        // Coloca a socket em um modo passivo, onde ela espera o cliente se comunicar 
        bool listenSocket();

        // Extrai a primeira conexao da fila de conexoes pendentes de espera e cria uma nova socket conectada 
        bool acceptSocket();

        // Envia uma mensagem 
        void sendMessage(std::string msg);

        // Recebe a mensagem
        void readMessage();

        // Conecta a socket do cleinte a do server 
        bool connectSocket();

        // Retorna o buffer 
        std::string& getBuffer();
};

#endif