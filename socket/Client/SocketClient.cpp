#include "SocketClient.h"
#include <iostream>

SocketClient::SocketClient(){
    socketClient_fd = 0;

    socketClient_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(socketClient_fd < 0){
      std::cout << "Operacão de init falhou" << std::endl;  
      return;
    } 

    portNumber = 8080;

    addressClient.sin_family = AF_INET;
    addressClient.sin_port = htons( portNumber );
}

void SocketClient::convertAdressSocket(){

    if(inet_pton(AF_INET, "127.0.0.1", &addressClient.sin_addr) <= 0){
        std::cout << "Operacao convert Address falhou \n";

        return;
    } 

    //std::cout << "Operacao convert Address sucesso \n";

}

bool SocketClient::connectSocket(){
    if (connect(socketClient_fd, (struct sockaddr *)&addressClient, sizeof(addressClient)) < 0){
        
        std::cout << "Operacao Connect falhou \n";

        return false;

    }
    

    //std::cout << "Operacao Connect sucesso \n";
    return true;
}

void SocketClient::sendMessage(std::string msg){

    std::cout << "Mensagem antes do send: " << msg << std::endl;

    if(send(socketClient_fd , msg.c_str(), msg.size(), 0 ) < 0){

        std::cout << "Operacao Send falhou \n";

        return;

    }

    //std::cout << "Operacao Send sucesso \n";

}

