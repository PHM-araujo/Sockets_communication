#include "Loja.h"
#include <iostream>
#include <iomanip>
#include <limits>

Loja::Loja(int port) : SocketServer(port) {

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
    int out = 1;

    conectPortSocket();

    bindSocket();

    do{

    printStock();
        
    std::cout << "Esperando por clientes...\n \n";
    listenSocket();

    acceptSocket();

    msg = readMessage();

    respondRequest(msg);

    validaInput(out, "\nDeseja manter a loja funcionando? Digite 0 p/ Não: ",1);

    }while(out);

    
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

    waterRequest = std::stoi (strAgua);

    for (unsigned i = aux; i < msg.size(); i++){
        if(msg[i] != ' '){
            strRefri += msg[i];
            aux = i;
        }else break;
    }
    aux += 2;

    refriRequest = std::stoi (strRefri);

    for (unsigned i = aux; i < msg.size(); i++){
        if(msg[i] != ' '){
            strCerva += msg[i];
        }else break;
    }

    cervaRequest = std::stoi (strCerva);
    
    std::cout << "------------Resultado do pedido------------" << std::endl;
    std::cout << "Pedido de agua: ";
    proccessStock(Agua, waterRequest);

    std::cout << "Pedido de refrigerante: ";
    proccessStock(Refri, refriRequest);

    std::cout << "Pedido de cerveja: ";
    proccessStock(Cerva, cervaRequest);
    std::cout << "------------------------" << std::endl;
}

void Loja::proccessStock(int posEstoque, int request){
    
    if((estoque[posEstoque] - request) >= 0){
        
        std::cout << "Seu pedido foi bem sucedido, estamos enviando para você a(s) " << request << " bebidas\n";
        estoque[posEstoque] -= request;
        
    }else if( (estoque[posEstoque] > 0) and (estoque[posEstoque] < request)){
        
        std::cout << "Estoque Insuficiente. Estamos encaminhando a(s) " << estoque[posEstoque] << " bebida(s) que sobraram\n";
        estoque[posEstoque] = 0;
                
    }else{
            
        std::cout << "Estamos sem estoque, perdao o incomodo\n";
    }
}

void Loja::printStock(){
    std::cout << std::endl;
    std::cout << "------------Estoque------------" << std::endl;
    std::cout << "Temos " << estoque[Agua] << " garrafa(s) de agua\n";
    std::cout << "Temos " << estoque[Refri] << " garrafa(s) de refrigerante\n";
    std::cout << "Temos " << estoque[Cerva] << " garrafa(s) de cerveja\n";
    std::cout << "------------------------" << std::endl;   
    std::cout << std::endl;    
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