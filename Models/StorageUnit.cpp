//
// Created by Vinicius on 03/11/2022.
//

#include "StorageUnit.h"

namespace Models {
    StorageUnit::StorageUnit(StorageType type, int writeSpeed, int readSpeed, string marca, string modelo, int id, int quantidade, double valor) : Hardware(marca, modelo, id, quantidade, valor){
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
        cout << "Quantidade: " << quantidade << endl;
        cout << "Valor: " << valor << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
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
}