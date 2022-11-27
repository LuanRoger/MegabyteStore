//
// Created by Vinicius on 27/10/2022.
//

#include "Motherboard.h"

namespace Models {
    Motherboard::Motherboard(string socket, string chipset, string memorySupport, string brand, string model, int id, int quantity, double value) : Hardware(brand, model, id, quantity, value), Socket(socket){
        setChipset(chipset);
        setMemorySupport(memorySupport);
    }


    string Motherboard::getChipset() {
        return chipset;
    }

    void Motherboard::setChipset(string newChipset) {
        chipset = newChipset;
    }

    string Motherboard::getMemorySupport() {
        return memorySupport;
    }

    void Motherboard::setMemorySupport(string newMemorySupport) {
        memorySupport = newMemorySupport;
    }

    void Motherboard::View(){
        cout << "ID: " << id << endl;
        cout << "Quantidade: " << quantity << endl;
        cout << "Valor: " << value << endl;
        cout << "Marca: " << brand << endl;
        cout << "Modelo: " << model << endl;
        cout << "Chipset: " << chipset << endl;
        cout << "Socket: " << type << endl;
        cout << "Suporte de Memoria: " << memorySupport << endl;
    }

    json Motherboard::ToJson() {

    }

    Motherboard* Motherboard::FromJson(json jsonObject) {

    }
}