#include "Loja.h"
#include <iostream>
#include <string>

Loja::Loja() : SocketServer() {

    int quant_agua, quant_refri, quant_cerva;

    std::cout << "Entre com o estoque de bebidas " << std::endl;
    
    validaInput(quant_agua, "Quantidades de águas: ", 1000);
    estoque.push_back(quant_agua);

    validaInput(quant_refri, "Quantidades de refrigerantes: ", 1000);
    estoque.push_back(quant_refri);

    validaInput(quant_cerva, "Quantidades de cervejas: ", 1000);
    estoque.push_back(quant_cerva);
    
}

void Loja::routine(){
    std::string msg;

    printStock();

    conectPortSocket();

    bindSocket();

    std::cout << "Esperando por clientes...\n";
    listenSocket();

    acceptSocket();

    msg = readMessage();

    respondRequest(msg);
}

void Loja::respondRequest(std::string msg){

    int waterRequest, refriRequest, cervaRequest;
    unsigned aux;
    std::string strAgua, strRefri, strCerva;

    for (unsigned i = 0; i < msg.size(); i++){
        if(msg[i] != ' '){
            strAgua += msg[i];
            aux = i;
        }else break;
    }
    aux += 2;

    std::cout << "string"  << strAgua << std::endl;
    waterRequest = std::stoi (strAgua);
    std::cout << "int"  << waterRequest << std::endl;

    for (unsigned i = aux; i < msg.size(); i++){
        if(msg[i] != ' '){
            strRefri += msg[i];
            aux = i;
        }else break;
    }
    aux += 3;

    std::cout << "string"  << strRefri << std::endl;
    refriRequest = std::stoi (strRefri);
    std::cout << "int"  << refriRequest << std::endl;

    for (unsigned i = aux; i < msg.size(); i++){
        if(msg[i] != ' '){
            strRefri += msg[i];
        }else break;
    }

    std::cout << "string"  << strCerva << std::endl;
    cervaRequest = std::stoi (strCerva);
    std::cout << "int"  << cervaRequest << std::endl;
    
    std::cout << "Pedido de agua:\n";
    proccessStock(Agua, waterRequest);

    std::cout << "Pedido de refrigerante:\n";
    proccessStock(Refri, refriRequest);

    std::cout << "Pedido de cerveja:\n";
    proccessStock(Cerva, cervaRequest);
}

void Loja::proccessStock(int posEstoque, int request){
    
    if((estoque[posEstoque] - request) >= 0){
        
        estoque[posEstoque] -= request;
        
    }else if( (estoque[posEstoque] > 0) and (estoque[posEstoque] < request)){
        
        std::cout << "Estoque Insuficiente. Estamos encaminhando tudo que sobrou\n";
        estoque[posEstoque] = 0;
                
    }else{
            
        std::cout << "Estamos sem estoque, perdao o incomodo\n";
    }
}

void Loja::printStock(){
    std::cout << "Temos " << estoque[Agua] << " garrafas de agua\n";
    std::cout << "Temos " << estoque[Refri] << " garrafas de refrigerante\n";
    std::cout << "Temos " << estoque[Cerva] << " garrafas de cerveja\n";       
}

void Loja::validaInteger(int& in, std::string out){
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

void Loja::validaInput(int& in, std::string out, int val_max){
    validaInteger(in, out);

	while(in < 0 || in > val_max){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		validaInteger(in, out);
	}
}