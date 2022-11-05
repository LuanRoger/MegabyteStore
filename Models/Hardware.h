//
// Created by Vinicius on 27/10/2022.
//

#ifndef MEGABYTESTORE_HARDWARE_H
#define MEGABYTESTORE_HARDWARE_H
#include "Product.h"
#include "string"
#include "iostream"

using namespace std;
namespace Models {
    class Hardware : public Product{
    protected:
        string marca;
        string modelo;
    public:
        Hardware(string marca, string modelo, int id, int quantidade, double valor);

        string getMarca();
        void setMarca(string novaMarca);

        string getModelo();
        void setModelo(string novoModelo);

        virtual void View();
    };
}

#endif //MEGABYTESTORE_HARDWARE_H
