//
// Created by Caio on 15/11/2022.
//

#ifndef CADASTRO_CLIENT_H
#define CADASTRO_CLIENT_H

#include <iostream>

#include "Cadastro.h"
#include "Login.h"

class Client {
private:
    int option;
public:
    Client();
    void chooseOption();
    void realizarCadastro();
    void realizarLogin();
    void valideOption(int option);
};


#endif //CADASTRO_CLIENT_H
