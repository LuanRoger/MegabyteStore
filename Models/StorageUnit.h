//
// Created by Vinicius on 03/11/2022.
//

#ifndef MEGABYTESTORE_STORAGEUNIT_H
#define MEGABYTESTORE_STORAGEUNIT_H
#include "Hardware.h"
#include "string"

using namespace std;

enum StorageType{HDD = 1, SSD, SSDNVME};

class StorageUnit : public Hardware{
private:
    StorageType type;
    int writeSpeed;
    int readSpeed;

public:
    StorageUnit(StorageType type, int writeSpeed, int readSpeed, string marca, string modelo, int id, int quantidade, double valor);

    StorageType getType();
    void setType(StorageType newType);

    int getWriteSpeed();
    void setWriteSpeed(int newWriteSpeed);

    int getReadSpeed();
    void setReadSpeed(int newReadSpeed);

    string getString();

    void View() override;



};


#endif //MEGABYTESTORE_STORAGEUNIT_H
