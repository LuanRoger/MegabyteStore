//
// Created by Vinicius on 27/10/2022.
//

#include "Hardware.h"
namespace Models {
    Hardware::Hardware(string marca, string modelo, int id, int quantidade, double valor) : Product(id, quantidade, valor){
        setMarca(marca);
        setModelo(modelo);
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


    void Hardware::View() {
        cout << "ID:" << id << endl;
        cout << "Quantidade:" << quantidade << endl;
        cout << "Valor:" << valor << endl;
        cout << "Marca:" << marca << endl;
        cout << "Modelo:" << modelo << endl;
    }
}