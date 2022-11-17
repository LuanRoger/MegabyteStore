//
// Created by Caio on 15/11/2022.
//

#ifndef CADASTRO_SESSION_H
#define CADASTRO_SESSION_H

#include <iostream>

#include "Login.h"
#include "Cadastro.h"
#include "Client.h"

class Session {
private:
    int option;
public:
    Session();
    void chooseOption();
    void valideOption(int option);


};


#endif //CADASTRO_SESSION_H
