#include "Cliente.h"
#include <iostream>
#include <string>

Cliente::Cliente() : Socket(){}

void Cliente::routine(){
    connectSocket();

    requestBeverage();
}

void Cliente::requestBeverage(){

    //int bebida, quant;
    std::string msg;

    msg = "Hello motherfuckers";


    std::cout << "Entre com o pedido" << std::endl;

    std::cout << "Tipo da bebida:" << std::endl;
    std::cout << "0 para água" << std::endl;
    std::cout << "1 para refrigerante" << std::endl;
    std::cout << "2 para cerveja" << std::endl;

    //std::cin >> bebida;

    std::cout << "Quantidade da bebida:" << std::endl;
    //std::cin >> quant;

    sendMessage(msg);
}