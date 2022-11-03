#include <iostream>
#include "Models/Produto.h"
#include "Models/Hardware.h"
#include "Models/PlacaMae.h"
#include "Models/CPU.h"
#include "Models/RAMMemory.h"
#include "Models/GPU.h"
#include "Models/StorageUnit.h"
using namespace std;

void OP1() {
    cout << "Opcao 1" << endl;

    CPU *Cpu1 = new CPU("AM4", 6, 12, 3.7, 4.6, "AMD", "100-100000065BOX", 1, 60, 1199.99);
    Cpu1->View();
    cout << "-------" << endl;
    RAMMemory *RAM1 = new RAMMemory("DDR4", 3200, 8, "HyperX", "KF432C16BBA/8", 2, 45, 259.99);
    RAM1->View();
    cout << "-------" << endl;
    GPU *GPU1 = new GPU("NVIDIA GeForce RTX 3060 Ti", 4864, 8, "GDDR6", 14, "MSI", "912-V397-234", 2, 10, 3799.99);
    GPU1->View();
    cout << "-------" << endl;

    StorageUnit *Storage1 = new StorageUnit(HDD, 350, 350, "Kingston", "A400", 1, 45, 300.00);
    Storage1->View();

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
