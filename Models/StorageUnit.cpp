//
// Created by Vinicius on 03/11/2022.
//

#include "StorageUnit.h"

namespace Models {
    StorageUnit::StorageUnit(StorageType type, int writeSpeed, int readSpeed, string brand, string model, int id, int quantity, double value) : Hardware(brand, model, id, quantity, value){
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

    std::string StorageUnit::ToJson() {
        return "adfsf";
    }

    StorageUnit *StorageUnit::FromJson(std::string jsonText) {

    }
}