//
// Created by Caio on 15/11/2022.
//
#include "Session.h"

using namespace std;

Session::Session() {
    cout << "-- ENTRAR --" << endl;
    cout << "Admin [0]" << endl;
    cout << "Client [1]" << endl;
    cout << "Deseja acessar como: " << endl;
}

void Session::chooseOption() {
    cin >>option;
    valideOption(option);
}

void Session::valideOption(int option) {
    if (option == 0){
        Login login;
        login.Logar();
    } else if (option == 1) {
        Client client;
        client.chooseOption();
    } else {
        cout << "Opcao inexistente!" << endl;
    }
}
