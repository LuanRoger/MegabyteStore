//
// Created by Vinicius on 28/10/2022.
//

#include "RAMMemory.h"

namespace Models {
    RAMMemory::RAMMemory(string memoryType, int frequency, int capacity, string brand, string model, int id,
                         int quantity, double value) : Hardware(brand, model, id, quantity, value){
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
        cout << "Quantidade: " << quantity << endl;
        cout << "Valor: " << value << endl;
        cout << "Marca: " << brand << endl;
        cout << "Modelo: " << model << endl;
        cout << "Tipo: " << memoryType << endl;
        cout << "Frequencia: " << frequency << endl;
        cout << "Capacidade: " << capacity << endl;
    }

    json RAMMemory::ToJson() {

    }

    RAMMemory* RAMMemory::FromJson(json jsonObject) {

    }
}