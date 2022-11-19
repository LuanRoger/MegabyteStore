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
        string brand;
        string model;
    public:
        Hardware(string brand, string model, int id, int quantity, double value);

        string getBrand();
        void setBrand(string newBrand);

        string getModel();
        void setModel(string newModel);

        virtual void View();
    };
}

#endif //MEGABYTESTORE_HARDWARE_H
