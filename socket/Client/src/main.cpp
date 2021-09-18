#include "Cliente.h"

int main(){
    Cliente cliente(8080, "127.0.0.1");

    cliente.routine();

    return 0;
}