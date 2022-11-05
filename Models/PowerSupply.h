//
// Created by Vinicius on 28/10/2022.
//

#ifndef MEGABYTESTORE_POWERSUPPLY_H
#define MEGABYTESTORE_POWERSUPPLY_H
#include "Hardware.h"
#include "string"

using namespace std;

namespace Models {
    class PowerSupply : Hardware{
    private:
        string outputCapacity;
        string inputVoltage;
        bool PFC;
        bool eightyPlusCertification;

    public:
        PowerSupply(string outputCapacity, string inputVoltage, bool PFC, bool eightyPlusCertification, string marca, string modelo, int id, int quantidade, double valor);

        string getOutputCapacity();
        void setOutputCapacity(string newOutputCapacity);

        string getInputVoltage();
        void setInputVoltage(string newInputVoltage);

        bool getPFC();
        void setPFC(bool newPFC);

        bool getEightyPlusCertification();
        void setEightyPlusCertification(bool newEightyPlusCertification);

        virtual void View();
    };
}

#endif //MEGABYTESTORE_POWERSUPPLY_H
