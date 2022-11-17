//
// Created by Caio on 16/11/2022.
//

#ifndef CADASTRO_ADMIN_H
#define CADASTRO_ADMIN_H

#include "Conta.h"

class Admin : Conta{
private:
    int option;
public:
    Admin();
    void chooseOption();
    void valideOption(int option);
    void print_lista(Conta p);
    void impressao();

};


#endif //CADASTRO_ADMIN_H
