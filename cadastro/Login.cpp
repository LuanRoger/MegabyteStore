//
// Created by Caio on 14/11/2022.
//

#include "Login.h"
#include <string>

using namespace std;

void Login::insertUser(){
    cout << "Digite seu usuario: " << endl;
    cin >> username;

}

void Login::insertPassword(){
    cout << "Digite sua senha: " << endl;
    cin >> password;
}

void Login::Logar() {
    insertUser();
    insertPassword();
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