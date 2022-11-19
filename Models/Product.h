//
// Created by Vinicius on 27/10/2022.
//

#ifndef MEGABYTESTORE_PRODUCT_H
#define MEGABYTESTORE_PRODUCT_H

namespace Models {
    class Product {
    protected:
        int id, quantity;
        double value;
    public:
        Product(int id, int quantity, double value);

        int getId();
        void setId(int newId);

        int getQuantity();
        void setQuantity(int newQuantity);


        double getValue();
        void setValue(double newValue);
    };
}

#endif //MEGABYTESTORE_PRODUCT_H
