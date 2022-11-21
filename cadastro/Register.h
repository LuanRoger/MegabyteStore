//
// Created by Caio on 17/11/2022.
//

#ifndef MEGABYTESTORE_REGISTER_H
#define MEGABYTESTORE_REGISTER_H

#include "../Models/Usuarios/Account.h"

class Register : public Account {
public:
    void signUp();
    void cadastroAdmin();
};


#endif //MEGABYTESTORE_REGISTER_H
