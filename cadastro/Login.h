//
// Created by Caio on 14/11/2022.
//

#ifndef CADASTRO_LOGIN_H
#define CADASTRO_LOGIN_H

#include "Conta.h"
#include "Admin.h"

class Login : public Conta {
private:
    Conta User;
public:
    Conta getUser ();
    void setUser (Conta User, string senha);
    void Logar();

};


#endif //CADASTRO_LOGIN_H
