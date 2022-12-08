//
// Created by luanr on 29/11/2022.
//

#ifndef MEGABYTESTORE_CART_H
#define MEGABYTESTORE_CART_H

#include <vector>
#include "Order.h"

namespace Models {

    class Cart {
    private:
        std::vector<Models::Order> orders;

    public:
        void AddOrder(Models::Order order);
        bool RemoveProduct(int id);
        void Clear();

        double getTotal();
        int getAmmount();

        const std::vector<Models::Order>& getOrders() const;
        int getProductQuantityInCard(int id) const;
    };

} // Models

#endif //MEGABYTESTORE_CART_H
