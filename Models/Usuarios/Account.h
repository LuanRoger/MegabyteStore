//
// Created by Caio on 17/11/2022.
//

#ifndef MEGABYTESTORE_ACCOUNT_H
#define MEGABYTESTORE_ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Account {
private:
    string name;
    string username;
    string password;
public:
    Account ();
    Account (string name, string username, string password);
    string getUsername ();
    string getPassword ();
};

#endif //MEGABYTESTORE_ACCOUNT_H
