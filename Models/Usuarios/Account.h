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
    static vector <Account> listOfUsers;
    Account ();
    Account (string name, string username, string password);
    string getUsername ();
    void setUsername (string username);
    string getPassword ();
    void setPassword (string password);
    bool valideUser(string username, string password);
};

#endif //MEGABYTESTORE_ACCOUNT_H
