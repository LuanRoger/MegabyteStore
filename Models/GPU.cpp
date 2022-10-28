//
// Created by Vinicius on 28/10/2022.
//

#include "GPU.h"

GPU::GPU(string chipset, int cudaCores, int VRAMCapacity, string VRAMType, int VRAMVelocity, string marca, string modelo, int id,
         int quantidade, double valor) : Hardware(marca, modelo, id, quantidade, valor){
    setChipset(chipset);
    setCudaCores(cudaCores);
    setVRAMCapacity(VRAMCapacity);
    setVRAMType(VRAMType);
    setVRAMVelocity(VRAMVelocity);
}

string GPU::getChipset() {
    return chipset;
}

void GPU::setChipset(string newChipset) {
    chipset = newChipset;
}

int GPU::getCudaCores() {
    return cudaCores;
}

void GPU::setCudaCores(int newCudaCores) {
    cudaCores = newCudaCores;
}

int GPU::getVRAMCapacity() {
    return VRAMCapacity;
}

void GPU::setVRAMCapacity(int newVRAMCapacity) {
    VRAMCapacity = newVRAMCapacity;
}

string GPU::getVRAMType() {
    return VRAMType;
}

void GPU::setVRAMType(string newVRAMType) {
    VRAMType = newVRAMType;
}

int GPU::getVRAMVelocity() {
    return VRAMVelocity;
}

void GPU::setVRAMVelocity(int newVRAMVelocity) {
    VRAMVelocity = newVRAMVelocity;
}

void GPU::View() {
    cout << "ID: " << id << endl;
    cout << "Quantidade: " << quantidade << endl;
    cout << "Valor: " << valor << endl;
    cout << "Marca: " << marca << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Chipset: " << chipset << endl;
    cout << "Nucleos Cuda: " << cudaCores << endl;
    cout << "Tipo VRAM: " << VRAMType << endl;
    cout << "Capacidade VRAM: " << VRAMCapacity << endl;
    cout << "Velocidade VRAM: " << VRAMVelocity << endl;
}


