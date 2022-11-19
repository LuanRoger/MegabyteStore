//
// Created by Caio on 16/11/2022.
//

#include "Admin.h"

Admin::Admin() {
    cout << "-- ENTRAR --" << endl;
    cout << "Ver usuarios registrados [0]" << endl;
    cout << "Digite a opcao desejada: " << endl;
}

void Admin::chooseOption() {
    cin >>option;
    valideOption(option);
}

void Admin::valideOption(int option) {
    if (option == 0) {
        retriveUsers();
    } else {
        cout << "Opcao inexistente!" << endl;
    }
}

void Admin::printList(Account User){
    cout << "---Name: " << User.getUsername() << " \n---Username:  " << User.getPassword() << endl;
    cout << endl;
}

void Admin::retriveUsers() {
    cout<<" Usuarios registrados:\n"<<endl;
    for (int i = 0; i<listOfUsers.size(); i++) {
        printList(listOfUsers[i]);
    }
}