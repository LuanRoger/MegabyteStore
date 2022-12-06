//
// Created by Vinicius on 27/10/2022.
//

#ifndef MEGABYTESTORE_PRODUCT_H
#define MEGABYTESTORE_PRODUCT_H

#include "../Utils/Json/JsonSerializable.h"
#include "Enums/ProductType.h"

using namespace JsonUtils;

namespace Models {
    class Product : public JsonSerializable {
    protected:
        int id, quantity;
        ProductType productType;
        double value;
    public:
        Product(int id, int quantity, double value, ProductType productType);

        int getId();
        void setId(int newId);

        int getQuantity();
        void setQuantity(int newQuantity);

        double getValue();
        void setValue(double newValue);

        virtual std::string ToString() = 0;
        virtual void View() = 0;

        json ToJson() override = 0;
    };
}

#endif //MEGABYTESTORE_PRODUCT_H
