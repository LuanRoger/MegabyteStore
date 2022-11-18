//
// Created by Caio on 14/11/2022.
//

#include "Login.h"
#include <string>

using namespace std;

Account Login::getUser () {
    return User;
}

void Login::setUser (Account User, string senha) {
    User.setPassword(senha);
}

void Login::Logar() {
    string username, password;

    cout << "Digite seu usuario: " << endl;
    cin >> username;
    cout << "Digite sua senha: " << endl;
    cin >> password;

    if(valideUser(username, password) == true) {
        cout << "Logado" << endl;
        if(username == "admin"){
            Admin adm;
            adm.chooseOption();
        }
    } else if(valideUser(username, password) != true) {
        cout << "Usuario ou senha incorretos!" << endl;
    }
}