//
// Created by Caio on 15/11/2022.
//

#include "Client.h"

using namespace std;

Client::Client() {
    cout << "-- Cliente --" << endl;
    cout << "Cadastrar [0]" << endl;
    cout << "Realizar login [1]" << endl;
    cout << "Digite se deseja se cadastrar ou realizar login: " << endl;
}


void Client::chooseOption() {
    cin >> option;
    valideOption(option);
}

void Client::valideOption(int option) {
    if (option == 0) {
        realizarCadastro();
    } else if (option == 1) {
        realizarLogin();
    } else {
        cout << "Opcao inexistente!";
    }
}

void Client::realizarCadastro() {
    Register newClient;
    newClient.signUp();
}

void Client::realizarLogin() {
    Login client;
    client.Logar();
}
