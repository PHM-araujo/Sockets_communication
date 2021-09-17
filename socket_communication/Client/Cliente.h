#ifndef CLIENTE_H
#define CLIENTE_H

#include "Socket.h"

class Cliente : public Socket{

    public:
        Cliente();
        void routine();
        void requestBeverage();

};

#endif