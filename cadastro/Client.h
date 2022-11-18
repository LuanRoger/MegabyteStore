//
// Created by Caio on 15/11/2022.
//

#ifndef CADASTRO_CLIENT_H
#define CADASTRO_CLIENT_H

#include <iostream>

#include "Register.h"
#include "Login.h"

class Client {
private:
    int option;
public:
    Client();
    void chooseOption();
    void valideOption(int option);
    void realizarCadastro();
    void realizarLogin();
};


#endif //CADASTRO_CLIENT_H
