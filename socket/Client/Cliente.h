#ifndef CLIENTE_H
#define CLIENTE_H

#include "SocketClient.h"

class Cliente : public SocketClient{

    public:
        enum Beverage{Agua = 0, Refri, Cerva};

    private:

        int quant_agua, quant_refri, quant_cerva;

    public:
        Cliente();
        void routine();
        std::string requestBeverage();
        void validaInteger(int& in, std::string out);
        void validaInput(int& in, std::string out, int val_max);

};

#endif