//
// Created by Vinicius on 03/11/2022.
//

#ifndef MEGABYTESTORE_STORAGEUNIT_H
#define MEGABYTESTORE_STORAGEUNIT_H
#include "Hardware.h"
#include "string"
#include "Enums/StorageType.h"

using namespace std;

namespace Models {
    class StorageUnit : public Hardware {
    private:
        StorageType type;
        int writeSpeed;
        int readSpeed;

    public:
        StorageUnit(StorageType type, int writeSpeed, int readSpeed, string brand, string model, int id, int quantity, double value);

        StorageType getType();
        void setType(StorageType newType);

        int getWriteSpeed();
        void setWriteSpeed(int newWriteSpeed);

        int getReadSpeed();
        void setReadSpeed(int newReadSpeed);

        string getString();

        void View() override;

        std::string ToJson() override;
        static StorageUnit* FromJson(std::string jsonText);
    };
}

#endif //MEGABYTESTORE_STORAGEUNIT_H
