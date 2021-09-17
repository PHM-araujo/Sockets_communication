#include "Socket.h"
#include <iostream>

Socket::Socket(){
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    portNumber = 8080;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( portNumber );
}

bool Socket::bindSocket(){

    if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        return false;   
    }
    
    return true;
    
}

bool Socket::listenSocket(){

    if(listen(socket_fd, 3)){
        return false;
    }

    return true;
}

bool Socket::acceptSocket(){

    newSocket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

    if(newSocket < 0){
        return false;
    }
    
    return true;

}

void Socket::sendMessage(std::string msg){
    send(newSocket , &msg, msg.size(), 0 );
}

void Socket::readMessage(){
    std::cout << "Num de caracteres " << read(newSocket , &buffer, 1024) << std::endl;
}

bool Socket::connectSocket(){
    if (connect(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        return false;
    }

    return true;
}

std::string& Socket::getBuffer(){
    return buffer;
}