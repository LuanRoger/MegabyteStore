//
// Created by Vinicius on 28/10/2022.
//

#include "GPU.h"
namespace Models {
    GPU::GPU(string chipset, int cudaCores, int VRAMCapacity, string VRAMType, int VRAMSpeed, string brand, string model, int id,
             int quantity, double value) : Hardware(brand, model, id, quantity, value, GPUTYPE){
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
        cout << "Quantidade: " << quantity << endl;
        cout << "Valor: " << value << endl;
        cout << "Marca: " << brand << endl;
        cout << "Modelo: " << model << endl;
        cout << "Chipset: " << chipset << endl;
        cout << "Nucleos Cuda: " << cudaCores << endl;
        cout << "Tipo VRAM: " << VRAMType << endl;
        cout << "Capacidade VRAM: " << VRAMCapacity << endl;
        cout << "Velocidade VRAM: " << VRAMSpeed << endl;
    }

    json GPU::ToJson() {
        json jsonGpu;
        jsonGpu = {
                { "id", id },
                {"type", productType },
                {"quantity", quantity},
                {"value", value},
                {"brand", brand},
                {"model", model},
                {"vram_capacity", VRAMCapacity},
                {"vram_speed", VRAMSpeed},
                {"vram_type", VRAMType},
                {"chipset", chipset},
                {"cuda_cores", cudaCores}
        };
        return jsonGpu;
    }

    GPU* GPU::FromJson(json jsonObject) {
        GPU* gpu = new GPU(jsonObject["chipset"],
                           jsonObject["cuda_cores"],
                           jsonObject["vram_capacity"],
                           jsonObject["vram_type"],
                           jsonObject["vram_speed"],
                           jsonObject["brand"],
                           jsonObject["model"],
                           jsonObject["id"],
                           jsonObject["quantity"],
                           jsonObject["value"]);

        return gpu;
    }
}