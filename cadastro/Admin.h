//
// Created by Caio on 16/11/2022.
//

#ifndef CADASTRO_ADMIN_H
#define CADASTRO_ADMIN_H

#include "../Models/Account.h"

class Admin : Account{
private:
    int option;
public:
    Admin();
    void chooseOption();
    void valideOption(int option);
    void printList(Account User);
    void retriveUsers();

};


#endif //CADASTRO_ADMIN_H
