//
// Created by Caio on 17/11/2022.
//

#include "Account.h"

using namespace std;

Account::Account () {
    name = "";
    username = "";
    password = "";
}

Account::Account (string name, string username, string password) {
    this->name = name;
    this->username = username;
    this->password = password;
}
string Account::getUsername () {
    return username;
}

string Account::getPassword () {
    return password;
}