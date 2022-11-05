//
// Created by Vinicius on 28/10/2022.
//

#include "RAMMemory.h"

namespace Models {
    RAMMemory::RAMMemory(string memoryType, int frequency, int capacity, string marca, string modelo, int id,
                         int quantidade, double valor) : Hardware(marca, modelo, id, quantidade, valor){
        this->memoryType = memoryType;
        this->frequency = frequency;
        this->capacity = capacity;
    }

    string RAMMemory::getMemoryType(){
        return memoryType;
    }

    void RAMMemory::setType(string newMemoryType) {
        memoryType = newMemoryType;
    }

    int RAMMemory::getFrequency() {
        return frequency;
    }

    void RAMMemory::setFrequency(int newFrequency) {
        frequency = newFrequency;
    }

    int RAMMemory::getCapacity() {
        return capacity;
    }

    void RAMMemory::setCapacity(int newCapacity) {
        capacity = newCapacity;
    }

    void RAMMemory::View() {
        cout << "ID: " << id << endl;
        cout << "Quantidade: " << quantidade << endl;
        cout << "Valor: " << valor << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Tipo: " << memoryType << endl;
        cout << "Frequencia: " << frequency << endl;
        cout << "Capacidade: " << capacity << endl;
    }
}