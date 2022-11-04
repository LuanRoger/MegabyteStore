//
// Created by Vinicius on 28/10/2022.
//

#include "PowerSupply.h"

PowerSupply::PowerSupply(string outputCapacity, string inputVoltage, bool PFC, bool eightyPlusCertification,
                         string marca, string modelo, int id, int quantidade, double valor) : Hardware(marca, modelo, id, quantidade, valor){
    setOutputCapacity(outputCapacity);
    setInputVoltage(inputVoltage);
    setPFC(PFC);
    setEightyPlusCertification(eightyPlusCertification);
}

string PowerSupply::getOutputCapacity() {
    return outputCapacity;
}

void PowerSupply::setOutputCapacity(string newOutputCapacity) {
    outputCapacity = newOutputCapacity;
}

string PowerSupply::getInputVoltage() {
    return inputVoltage;
}

void PowerSupply::setInputVoltage(string newInputVoltage) {
    inputVoltage = newInputVoltage;
}

bool PowerSupply::getPFC() {
    return PFC;
}

void PowerSupply::setPFC(bool newPFC) {
    PFC = newPFC;
}

bool PowerSupply::getEightyPlusCertification() {
    return eightyPlusCertification;
}

void PowerSupply::setEightyPlusCertification(bool newEightyPlusCertification) {
    eightyPlusCertification = newEightyPlusCertification;
}

void PowerSupply::View() {
    cout << "ID: " << id << endl;
    cout << "Quantidade: " << quantidade << endl;
    cout << "Valor: " << valor << endl;
    cout << "Marca: " << marca << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Capacidade de saida: " << outputCapacity << endl;
    cout << "Voltagem da entrada: " << inputVoltage << endl;
    cout << "PFC ativo: " << (PFC ? "Sim" : "Não") << endl;
    cout << "Certificação 80 plus: " << (eightyPlusCertification ? "Sim" : "Não") << endl;
}






