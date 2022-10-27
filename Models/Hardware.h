//
// Created by Vinicius on 27/10/2022.
//

#ifndef MEGABYTESTORE_HARDWARE_H
#define MEGABYTESTORE_HARDWARE_H
#include "Produto.h"
#include "string"
#include "iostream"

using namespace std;

class Hardware : public Produto{
protected:
    string marca;
    string modelo;
    double tdp;
public:
    Hardware(string marca, string modelo, double tdp, int id, int quantidade, double valor);

    string getMarca();
    void setMarca(string novaMarca);

    string getModelo();
    void setModelo(string novoModelo);

    double getTdp();
    void setTdp(double novoTdp);

    virtual void View();
};


#endif //MEGABYTESTORE_HARDWARE_H
