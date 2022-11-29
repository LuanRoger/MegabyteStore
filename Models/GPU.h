//
// Created by Vinicius on 28/10/2022.
//

#ifndef MEGABYTESTORE_GPU_H
#define MEGABYTESTORE_GPU_H
#include "Hardware.h"
#include "string"

using namespace std;

namespace Models {
    class GPU : public Hardware{
    private:
        string chipset;
        int cudaCores;
        int VRAMCapacity;
        string VRAMType;
        int VRAMSpeed;
    public:
        GPU(string chipset, int cudaCores, int VRAMCapacity, string VRAMType, int VRAMSpeed, string brand, string model, int id, int quantity, double value, int productType);

        string getChipset();
        void setChipset(string newChipset);

        int getCudaCores();
        void setCudaCores(int newCudaCores);

        int getVRAMCapacity();
        void setVRAMCapacity(int newVRAMCapacity);

        string getVRAMType();
        void setVRAMType(string newVRAMType);

        int getVRAMSpeed();
        void setVRAMSpeed(int newVRAMSpeed);

        void View() override;

        json ToJson() override;
        static GPU* FromJson(json jsonObject);
    };
}

#endif //MEGABYTESTORE_GPU_H
