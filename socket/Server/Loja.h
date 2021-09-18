#ifndef LOJA_H
#define LOJA_H

#include "SocketServer.h"
#include <vector>
#include <iomanip>

class Loja : public SocketServer{
    
    public:
        enum Beverage{Agua = 0, Refri, Cerva};

    private:
        std::vector<int> estoque;


    public:
        Loja();
        void routine();
        void respondRequest(std::string msg);
        void printStock();
        void proccessStock(int posEstoque, int request);
        void validaInteger(int& in, std::string out);
        void validaInput(int& in, std::string out, int val_max);

};

#endif