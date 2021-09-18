#include "SocketServer.h"
#include <iostream>

SocketServer::SocketServer(){

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    portNumber = 8080;
    opt = 1;
    addrlen = sizeof(address);
    

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( portNumber );
}

void SocketServer::bindSocket(){

    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        std::cout << "Operacao bind falhou \n";

        return;
    }
    //std::cout << "Operacao bind sucesso \n";
    
}

void SocketServer::listenSocket(){

    if(listen(socket_fd, 1) < 0){
        std::cout << "Operacao listen falhou \n";

        return;
    }
    //std::cout << "Operacao listen sucesso \n";
}

void SocketServer::acceptSocket(){

    newSocket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

    if(newSocket < 0){
        std::cout << "Operacao accept falhou \n";

        return;
    }

    //std::cout << "Operacao accept sucesso \n";

}

std::string SocketServer::readMessage(){
    char msg[1024];

    read(newSocket , msg, 1024);

    return msg;
}

void SocketServer::conectPortSocket(){
    // Conectando o Socket a porta 8080
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        std::cout << "Operacao socketopt falhou \n";

        return;
    }
    //std::cout << "Operacao socketopt sucesso \n";

}