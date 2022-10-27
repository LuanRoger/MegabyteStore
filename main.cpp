#include <iostream>
#include "Models/Produto.h"
#include "Models/Hardware.h"
#include "Models/PlacaMae.h"
#include "Models/CPU.h"
using namespace std;

void OP1() {
    cout << "Opcao 1" << endl;

    CPU *Cpu1 = new CPU("AM4", 6, 12, 3.7, 4.6, "AMD", "100-100000065BOX", 65, 1, 60, 1199.99);
    Cpu1->View();

}
void OP2() {
    cout << "Opcao 2" << endl;
}
void OP3() {
    cout << "Opcao 3" << endl;
}

int main() {
    cout << "  Megabyte Store  " << endl;

    bool running = true;
    while (running) {
        int choice;
        cout << "[ 1 ] - Ver catalogo." << endl;
        cout << "[ 2 ] - Ver carrinho." << endl;
        cout << "[ 0 ] - Sair." << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                OP1();
                break;
            case 2:
                OP2();
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Está não é uma opção valida." << endl;
        }
    }

    return 0;
}
