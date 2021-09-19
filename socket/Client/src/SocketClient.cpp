#include "SocketClient.h"
#include <iostream>

SocketClient::SocketClient(int port, std::string IP) : portNumber(port), ip(IP){
    socketClient_fd = 0;

    socketClient_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(socketClient_fd < 0){
      std::cout << "Operacão de init falhou" << std::endl;  
      return;
    } 

    addressClient.sin_family = AF_INET;
    addressClient.sin_port = htons( portNumber );
}

void SocketClient::convertAdressSocket(){

    if(inet_pton(AF_INET, ip.c_str(), &addressClient.sin_addr) <= 0){
        std::cout << "Operacao convert Address falhou \n";

        return;
    } 

    //std::cout << "Operacao convert Address sucesso \n";

}

bool SocketClient::connectSocket(){
    if (connect(socketClient_fd, (struct sockaddr *)&addressClient, sizeof(addressClient)) < 0){
        
        // std::cout << "Operacao Connect falhou \n";

        return false;

    }
    

    //std::cout << "Operacao Connect sucesso \n";
    return true;
}

void SocketClient::sendMessage(std::string msg){

    if(send(socketClient_fd , msg.c_str(), msg.size(), 0 ) < 0){

        std::cout << "Operacao Send falhou \n";

        return;

    }

    //std::cout << "Operacao Send sucesso \n";

}

