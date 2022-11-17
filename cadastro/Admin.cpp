//
// Created by Caio on 16/11/2022.
//

#include "Admin.h"

Admin::Admin() {
    cout << "-- ENTRAR --" << endl;
    cout << "Ver usuarios registrados [0]" << endl;
    cout << "Deseja acessar como: " << endl;
}

void Admin::chooseOption() {
    cin >>option;
    valideOption(option);
}

void Admin::valideOption(int option) {
    if (option == 0) {
        impressao();
    } else {
        cout << "Opcao inexistente!" << endl;
    }
}

void Admin::print_lista(Conta p){
    cout << "---Name: " << p.getUsuario() << " \n---Username:  " << p.getSenha() << endl;
    cout << endl;
}

void Admin::impressao() {
    cout<<" Usuarios registrados:\n"<<endl;
    for (int i = 0; i<listaUsuarios.size(); i++) {
        print_lista(listaUsuarios[i]);
    }
}