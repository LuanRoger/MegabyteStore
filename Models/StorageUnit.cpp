//
// Created by Vinicius on 03/11/2022.
//

#include "StorageUnit.h"

namespace Models {
    StorageUnit::StorageUnit(StorageType type, int writeSpeed, int readSpeed, string brand, string model, int id, int quantity, double value) : Hardware(brand, model, id, quantity, value, STORAGEUNITTYPE){
        setType(type);
        setWriteSpeed(writeSpeed);
        setReadSpeed(readSpeed);

    }

    StorageType StorageUnit::getType() {
        return type;
    }

    void StorageUnit::setType(StorageType newType) {
        type = newType;
    }

    int StorageUnit::getWriteSpeed() {
        return writeSpeed;
    }

    void StorageUnit::setWriteSpeed(int newWriteSpeed) {
        writeSpeed = newWriteSpeed;
    }

    int StorageUnit::getReadSpeed() {
        return readSpeed;
    }

    void StorageUnit::setReadSpeed(int newReadSpeed) {
        readSpeed = newReadSpeed;
    }

    void StorageUnit::View() {
        cout << "ID: " << id << endl;
        cout << "Quantidade: " << quantity << endl;
        cout << "Valor: " << value << endl;
        cout << "Marca: " << brand << endl;
        cout << "Modelo: " << model << endl;
        cout << "Tipo: " <<  getString() << endl;
        cout << "Velocidade de escrita: " << writeSpeed << endl;
        cout << "Velocidade de leitura: " << readSpeed << endl;
    }

    string StorageUnit::getString() {
        switch (type) {
            case HDD:
                return "HDD";
            case SSD:
                return "SSD";
            case SSDNVME:
                return "SSDNVME";
            default:
                return "GENERICO";
        }
    }

    json StorageUnit::ToJson() {
        json jsonStorageUnit;
        jsonStorageUnit = {
                { "id", id },
                {"quantity", quantity},
                {"value", value},
                {"brand", brand},
                {"model", model},
                {"type", type},
                {"write_speed", writeSpeed},
                {"read_speed", readSpeed},
        };
        return jsonStorageUnit;
    }

    StorageUnit *StorageUnit::FromJson(json jsonObject) {
        StorageUnit* storageUnit = new StorageUnit(jsonObject["type"],
                           jsonObject["write_speed"],
                           jsonObject["read_speed"],
                           jsonObject["brand"],
                           jsonObject["model"],
                           jsonObject["id"],
                           jsonObject["quantity"],
                           jsonObject["value"]);

        return storageUnit;
    }
}