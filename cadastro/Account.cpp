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

bool Account::valideUser(string username, string password){
    for (int i = 0; i<listOfUsers.size(); i++) {
        if(listOfUsers[i].getUsername()==username && listOfUsers[i].getPassword() == password) {
            return true;
        }
    }
    return false;
}
vector <Account> Account::listOfUsers;
