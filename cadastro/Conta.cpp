//
// Created by Caio on 14/11/2022.
//

#include "Conta.h"
using namespace std;

Conta::Conta () {
    nome = "";
    usuario = "";
    senha = "";
}

Conta::Conta (string nome, string usuario, string senha) {
    this->nome = nome;
    this->usuario = usuario;
    this->senha = senha;
}
string Conta::getUsuario () {
    return usuario;
}
void Conta::setUsuario (string usuario) {
    this->usuario = usuario;
}

string Conta::getSenha () {
    return senha;
}

void Conta::setSenha (string senha) {
    this->senha = senha;
}

bool Conta::validaUsuario(string usuario, string senha){
    for (int i = 0; i<listaUsuarios.size(); i++) {
        if(listaUsuarios[i].getUsuario()==usuario && listaUsuarios[i].getSenha()==senha) {
            return true;
        }
    }
    return false;
}
vector <Conta> Conta::listaUsuarios;
