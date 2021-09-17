#ifndef LOJA_H
#define LOJA_H

#include "Socket.h"

class Loja : public Socket{
    
    public:
        enum Beverage{Agua = 0, Refri, Cerva};

    private:
    int quant_agua, quant_refri, quant_cerv;

    public:
        Loja();
        void routine();
        void respondRequest(int bebida, int quantidade);
        void printStock();

};

#endif