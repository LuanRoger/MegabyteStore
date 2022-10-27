//
// Created by Vinicius on 27/10/2022.
//

#include "PlacaMae.h"

PlacaMae::PlacaMae(string socket, string chipset, string memorySupport, string marca, string modelo, double tdp, int id, int quantidade, double valor) : Hardware(marca, modelo, tdp, id, quantidade, valor), Socket(socket){
    setChipset(chipset);
    setMemorySupport(memorySupport);
}


string PlacaMae::getChipset() {
    return chipset;
}

void PlacaMae::setChipset(string novoChipset) {
    chipset = novoChipset;
}

string PlacaMae::getMemorySupport() {
    return memorySupport;
}

void PlacaMae::setMemorySupport(string newMemorySupport) {
    memorySupport = newMemorySupport;
}

void PlacaMae::View(){
    cout << "ID: " << id << endl;
    cout << "Quantidade: " << quantidade << endl;
    cout << "Valor: " << valor << endl;
    cout << "Marca: " << marca << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Tdp: " << tdp << endl;
    cout << "Chipset: " << chipset << endl;
    cout << "Socket: " << type << endl;
    cout << "Suporte de Memoria: " << memorySupport << endl;
}

