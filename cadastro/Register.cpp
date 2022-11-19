//
// Created by Caio on 17/11/2022.
//

#include "Register.h"

#include <string>

using namespace std;

void Register::signUp() {
    string name, username, password;

    cout << "Digite seu nome: " << endl;
    cin >> name;
    cout << "Digite seu usuario: " << endl;
    cin >> username;
    cout << "Digite sua senha: " << endl;
    cin >> password;

    Account newUser(name, username, password);
    listOfUsers.push_back(newUser);
}

void Register::cadastroAdmin() {
    Account admin("admin", "admin", "admin");
    listOfUsers.push_back(admin);
    Account lucas("Lucas", "luc", "7768");
    listOfUsers.push_back(lucas);
}