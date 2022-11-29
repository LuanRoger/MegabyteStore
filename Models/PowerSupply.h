//
// Created by Vinicius on 28/10/2022.
//

#ifndef MEGABYTESTORE_POWERSUPPLY_H
#define MEGABYTESTORE_POWERSUPPLY_H
#include "Hardware.h"
#include "string"

using namespace std;

namespace Models {
    class PowerSupply : public Hardware {
    private:
        string outputCapacity;
        string inputVoltage;
        bool PFC;
        bool eightyPlusCertification;

    public:
        PowerSupply(string outputCapacity, string inputVoltage, bool PFC, bool eightyPlusCertification, string marca, string modelo, int id, int quantidade, double valor, int productType);

        string getOutputCapacity();
        void setOutputCapacity(string newOutputCapacity);

        string getInputVoltage();
        void setInputVoltage(string newInputVoltage);

        bool getPFC();
        void setPFC(bool newPFC);

        bool getEightyPlusCertification();
        void setEightyPlusCertification(bool newEightyPlusCertification);

        void View() override;

        json ToJson() override;
        static PowerSupply* FromJson(json jsonObject);
    };
}

#endif //MEGABYTESTORE_POWERSUPPLY_H
