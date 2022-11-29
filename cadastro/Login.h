//
// Created by Caio on 14/11/2022.
//

#ifndef CADASTRO_LOGIN_H
#define CADASTRO_LOGIN_H

#include "../Models/Account.h"
#include "Admin.h"

class Login : public Account {
private:
    Account User;
public:
    Account getUser ();
    void setUser (Account User, string senha);
    void Logar();

};


#endif //CADASTRO_LOGIN_H
