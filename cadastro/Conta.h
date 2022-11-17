//
// Created by Caio on 14/11/2022.
//

#ifndef CADASTRO_CONTA_H
#define CADASTRO_CONTA_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Conta {
private:
    string nome;
    string usuario;
    string senha;
public:
    static vector <Conta> listaUsuarios;
    Conta ();
    Conta (string nome, string usuario, string senha);
    string getUsuario ();
    void setUsuario (string usuario);
    string getSenha ();
    void setSenha (string senha);
    bool validaUsuario(string usuario, string senha);
};


#endif //CADASTRO_CONTA_H
