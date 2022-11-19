//
// Created by Vinicius on 27/10/2022.
//

#include "Product.h"

namespace Models {
    Product::Product(int id, int quantity, double value) {
        setId(id);
        setQuantity(quantity);
        setValue(value);
    }

    int Product::getId() {
        return id;
    }

    void Product::setId(int novoId) {
        id = novoId;
    }

    int Product::getQuantity() {
        return quantity;
    }

    void Product::setQuantity(int newQuantity) {
        quantity = newQuantity;
    }

    double Product::getValue() {
        return value;
    }

    void Product::setValue(double newValue) {
        value = newValue;
    }
}