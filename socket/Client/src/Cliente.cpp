#include "Cliente.h"
#include <iostream>
#include <iomanip>
#include <limits>

Cliente::Cliente(int port, std::string IP) : SocketClient(port, IP){
    quant_agua = 0;
    quant_refri = 0;
    quant_cerva = 0;
}

void Cliente::routine(){

    std::string msg = requestBeverage();
    
    convertAdressSocket();

    std::cout << "Esperando Loja..." << std::endl;
    while(!connectSocket());

    sendMessage(msg);
    
}

std::string Cliente::requestBeverage(){
    std::string msg;

    std::cout << "Entre com o pedido" << std::endl;

    validaInput(quant_agua, "Quantidades de águas desejadas: ", 1000);

    validaInput(quant_refri, "Quantidades de refrigerantes desejadas: ", 1000);

    validaInput(quant_cerva, "Quantidades de cervejas desejadas: ", 1000);

    msg += std::to_string(quant_agua) + " " + std::to_string(quant_refri) + " " +  std::to_string(quant_cerva) + " ";

    return msg;
}

void Cliente::validaInteger(int& in, std::string out){
    std::cout << out;
	std::cin >> std::setw(1) >> in;

	while(!std::cin.good()){
		// Reporta o erro
		std::cout << "Entrada inválida. Tente novamente:" << std::endl;
		std::cout << out;

		// Limpa o fluxo de entrada
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// Pega a entrada novamente 
		std::cin >> std::setw(1) >> in;
	}
}

void Cliente::validaInput(int& in, std::string out, int val_max){
    validaInteger(in, out);

	while(in < 0 || in > val_max){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		validaInteger(in, out);
	}
}
