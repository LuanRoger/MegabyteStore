//
// Created by Vinicius on 27/10/2022.
//

#include "Hardware.h"

Hardware::Hardware(string marca, string modelo, double tdp, int id, int quantidade, double valor) : Produto(id, quantidade, valor){
    setMarca(marca);
    setModelo(modelo);
    setTdp(tdp);
}

string Hardware::getMarca() {
    return modelo;
}

void Hardware::setMarca(string novaMarca) {
    marca = novaMarca;
}

string Hardware::getModelo() {
    return modelo;
}

void Hardware::setModelo(string novoModelo) {
    modelo = novoModelo;
}

double Hardware::getTdp() {
    return tdp;
}

void Hardware::setTdp(double novoTdp) {
    tdp = novoTdp;
}

void Hardware::View() {
    cout << "ID:" << id << endl;
    cout << "Quantidade:" << quantidade << endl;
    cout << "Valor:" << valor << endl;
    cout << "Marca:" << marca << endl;
    cout << "Modelo:" << modelo << endl;
    cout << "Tdp:" << tdp << endl;
}
