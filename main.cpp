#include <iostream>

using namespace std;

void OP1() {
    cout << "Opção 1" << endl;
}
void OP2() {
    cout << "Opção 2" << endl;
}
void OP3() {
    cout << "Opção 3" << endl;
}

int main() {
    cout << "╔══════════════════╗" << endl;
    cout << "║  Megabyte Store  ║" << endl;
    cout << "╚══════════════════╝" << endl;

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
