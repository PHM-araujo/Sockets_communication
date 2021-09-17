#include "Loja.h"
#include <iostream>

Loja::Loja() : Socket() {

    std::cout << "Entre com o estoque de bebidas " << std::endl;
    std::cout << "\nQuantidades de águas: ";
    std::cin >> quant_agua;
    std::cout << "\nQuantidades de refrigerantes: ";
    std::cin >> quant_refri;
    std::cout << "\nQuantidades de cervejas: ";
    std::cin >> quant_cerv;
    
}

void Loja::routine(){
    //int bebida, quantidade;

    std::string msg;

    printStock();

    std::cout << "Operação bind: " << bindSocket() << std::endl;

    std::cout << "Operação listem: " << listenSocket() << std::endl;

    std::cout << "Operação Accept: " << acceptSocket() << std::endl;

    readMessage();

    msg = getBuffer();

    std::cout << msg << std::endl; 

    //respondRequest(bebida, quantidade);
}

void Loja::respondRequest(int bebida, int quantidade){

    switch (bebida)
    {

    case Agua:    
        if( (quant_agua - quantidade) >= 0){
            
            quant_agua -= quantidade;
            
        }else if( (quant_agua > 0) and (quant_agua < quantidade)){
            
            //mensagem de foi todo o estoque que restou
            quant_agua = 0;
                    
        }else{
            
            //mensagem de insuficiente
            
        }
        break;

    case Refri:    
        if( (quant_refri - quantidade) >= 0){

            quant_refri -= quantidade;
            
        }else if( (quant_refri > 0) and (quant_refri < quantidade) ){

            //mensagem de foi todo o estoque que restou
            quant_refri = 0;
            
        
        }else{
            //mensagem de insuficiente
        }
        break;

    case Cerva:    
        if( (quant_cerv - quantidade) >= 0){
            quant_cerv -= quantidade;

        }else if( (quant_cerv > 0) and (quant_cerv < quantidade) ){
            //mensagem de foi todo o estoque que restou
            quant_cerv = 0;
        
        }else{           
            //mensagem de insuficiente
            
        }
        break;
    }
}

void Loja::printStock(){
    std::cout << "\nTemos " << quant_agua << " garrafas de agua\n";
    std::cout << "Temos " << quant_refri << " garrafas de refrigerante\n";
    std::cout << "Temos " << quant_cerv << " garrafas de cerveja\n";
        
}