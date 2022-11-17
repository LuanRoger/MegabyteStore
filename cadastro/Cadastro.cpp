//
// Created by Caio on 14/11/2022.
//

#include "Cadastro.h"
#include <string>

using namespace std;

void Cadastro::formularInscricao() {
    string nome, usuario, senha;

    cout << "Digite seu nome: " << endl;
    cin >> nome;
    cout << "Digite seu usuario: " << endl;
    cin >> usuario;
    cout << "Digite sua senha: " << endl;
    cin >> senha;

    Conta novaConta(nome, usuario, senha);
    listaUsuarios.push_back(novaConta);
}

void Cadastro::cadastroAdmin() {
    Conta admin("admin", "admin", "admin");
    listaUsuarios.push_back(admin);
    Conta lucas("Lucas", "luc", "7768");
    listaUsuarios.push_back(lucas);
}