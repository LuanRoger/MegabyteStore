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
void Account::setUsername (string username) {
    this->username = username;
}

string Account::getPassword () {
    return password;
}

void Account::setPassword (string password) {
    this->password = password;
}


vector <Account> Account::listOfUsers;
