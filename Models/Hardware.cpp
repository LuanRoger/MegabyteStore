//
// Created by Vinicius on 27/10/2022.
//

#include "Hardware.h"
namespace Models {
    Hardware::Hardware(string brand, string model, int id, int quantity, double value, int productType) : Product(id, quantity, value, productType){
        setBrand(brand);
        setModel(model);
    }

    string Hardware::getBrand() {
        return brand;
    }

    void Hardware::setBrand(string newBrand) {
        brand = newBrand;
    }

    string Hardware::getModel() {
        return model;
    }

    void Hardware::setModel(string newModel) {
        model = newModel;
    }


    void Hardware::View() {
        cout << "ID:" << id << endl;
        cout << "Quantidade:" << quantity << endl;
        cout << "Valor:" << value << endl;
        cout << "Marca:" << brand << endl;
        cout << "Modelo:" << model << endl;
    }
}