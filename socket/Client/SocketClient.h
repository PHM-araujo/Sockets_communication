#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

class SocketClient{

    private:
        int portNumber;
        struct sockaddr_in addressClient;
        int socketClient_fd;

    public:

        SocketClient();

        // Converte enedereços IPv4 em 
        void convertAdressSocket();

        // Conecta a socket do cliente a do server 
        bool connectSocket();

        // Envia uma mensagem 
        void sendMessage(std::string msg);


};

#endif