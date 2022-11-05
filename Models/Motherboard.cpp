//
// Created by Vinicius on 27/10/2022.
//

#include "Motherboard.h"

namespace Models {
    Motherboard::Motherboard(string socket, string chipset, string memorySupport, string marca, string modelo, int id, int quantidade, double valor) : Hardware(marca, modelo, id, quantidade, valor), Socket(socket){
        setChipset(chipset);
        setMemorySupport(memorySupport);
    }


    string Motherboard::getChipset() {
        return chipset;
    }

    void Motherboard::setChipset(string novoChipset) {
        chipset = novoChipset;
    }

    string Motherboard::getMemorySupport() {
        return memorySupport;
    }

    void Motherboard::setMemorySupport(string newMemorySupport) {
        memorySupport = newMemorySupport;
    }

    void Motherboard::View(){
        cout << "ID: " << id << endl;
        cout << "Quantidade: " << quantidade << endl;
        cout << "Valor: " << valor << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Chipset: " << chipset << endl;
        cout << "Socket: " << type << endl;
        cout << "Suporte de Memoria: " << memorySupport << endl;
    }
}