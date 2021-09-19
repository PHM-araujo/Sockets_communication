#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

class SocketClient{

    private:
        int portNumber, socketClient_fd;
        struct sockaddr_in addressClient;
        std::string ip;

    public:

        SocketClient(int port, std::string IP);

        // Converte enedereços IPv4 em 
        void convertAdressSocket();

        // Conecta a socket do cliente a do server 
        bool connectSocket();

        // Envia uma mensagem 
        void sendMessage(std::string msg);


};

#endif