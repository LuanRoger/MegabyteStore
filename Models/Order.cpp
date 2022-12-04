//
// Created by luanr on 29/11/2022.
//

#include "Order.h"

namespace Models {
    Order::Order(int productId, int quantity, double productBaseValue) {
        this->productId = productId;
        this->quantity = quantity;
        this->productBaseValue = productBaseValue;
    }

    int Order::getProductId() {
        return productId;
    }

    int Order::getQuantity() {
        return quantity;
    }

    double Order::getProductBaseValue() {
        return productBaseValue;
    }

    double Order::getTotal() {
        return productBaseValue * quantity;
    }
} // Models