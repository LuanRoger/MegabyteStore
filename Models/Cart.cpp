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

    bool Cart::RemoveProduct(int id) {
        int orderIndex = -1;

        int counter = 0;
        for (Models::Order order : orders) {
            if(id == order.getProductId()) {
                orderIndex = counter;
                break;
            }
            counter++;
        }

        if(orderIndex == -1) return false;

        orders.erase(orders.begin() + counter);
        return true;
    }
} // Models