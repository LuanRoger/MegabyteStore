//
// Created by Caio on 14/11/2022.
//

#include "Login.h"
#include <string>

using namespace std;

Conta Login::getUser () {
    return User;
}

void Login::setUser (Conta User, string senha) {
    User.setSenha(senha);
}

void Login::Logar() {
    string usuario, senha;

    cout << "Digite seu usuario: " << endl;
    cin >> usuario;
    cout << "Digite sua senha: " << endl;
    cin >> senha;

    if(validaUsuario(usuario, senha) == true) {
        cout << "Logado" << endl;
        if(usuario == "admin"){
            Admin adm;
            adm.chooseOption();
        }
    } else if(validaUsuario(usuario, senha) != true) {
        cout << "Usuario ou senha incorretos!" << endl;
    }
}