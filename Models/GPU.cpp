//
// Created by Vinicius on 28/10/2022.
//

#include "GPU.h"
namespace Models {
    GPU::GPU(string chipset, int cudaCores, int VRAMCapacity, string VRAMType, int VRAMSpeed, string marca, string modelo, int id,
             int quantidade, double valor) : Hardware(marca, modelo, id, quantidade, valor){
        setChipset(chipset);
        setCudaCores(cudaCores);
        setVRAMCapacity(VRAMCapacity);
        setVRAMType(VRAMType);
        setVRAMSpeed(VRAMSpeed);
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

    int GPU::getVRAMSpeed() {
        return VRAMSpeed;
    }

    void GPU::setVRAMSpeed(int newVRAMSpeed) {
        VRAMSpeed = newVRAMSpeed;
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
        cout << "Velocidade VRAM: " << VRAMSpeed << endl;
    }
}