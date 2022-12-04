//
// Created by Caio on 14/11/2022.
//

#ifndef CADASTRO_LOGIN_H
#define CADASTRO_LOGIN_H

#include "../Models/Account.h"
#include "Admin.h"

class Login : public Account {
private:
    string username;
    string password;
public:
    void insertUser();
    void insertPassword();
    void Logar();
};


#endif //CADASTRO_LOGIN_H
