//
// Created by luanr on 29/11/2022.
//

#include <algorithm>
#include "Cart.h"

namespace Models {
    double Cart::getTotal() {
        double total = 0;
        for (Order order : orders)
            total += order.getTotal();

        return total;
    }
    int Cart::getAmmount() {
        int total = 0;
        for (Order order : orders)
            total += order.getQuantity();

        return total;
    }

    const std::vector<Models::Order> &Cart::getOrders() const {
        return orders;
    }

    void Cart::AddOrder(Order order) {
        orders.push_back(order);
    }

    void Cart::RemoveProduct(int id) {
        std::remove_if(orders.begin(), orders.end(), [&](Order item) {
            return item.getProductId() == id;
        });
    }
} // Models