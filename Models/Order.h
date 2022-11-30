//
// Created by luanr on 29/11/2022.
//

#ifndef MEGABYTESTORE_ORDER_H
#define MEGABYTESTORE_ORDER_H

namespace Models {

    class Order {
    private:
        int productId;
        int quantity;
        double productBaseValue;
    public:
        Order(int productId, int quantity, double productBaseValue);

        int getProductId();
        int getQuantity();
        double getTotal();

        double getProductBaseValue();
    };

} // Models

#endif //MEGABYTESTORE_ORDER_H
