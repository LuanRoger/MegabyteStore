//
// Created by luanr on 06/12/2022.
//

#include "Sales.h"

namespace Models {
    Sales::Sales(int soldItems, double profit) {
        this->soldItems = soldItems;
        this->profit = profit;
    }

    void Sales::IncrementItems(int quantity) {
        soldItems += quantity;
    }

    void Sales::IncrementProfit(double quantity) {
        profit += quantity;
    }

    int Sales::getSoldItems() {
        return soldItems;
    }

    double Sales::getProfit() {
        return profit;
    }

    json Sales::ToJson() {
        json salesJson = {
                { "soldItems", soldItems },
                { "profit", profit }
        };

        return salesJson;
    }

    Sales *Sales::FromJson(json jsonObject) {
        auto* sales = new Sales(jsonObject["soldItems"],
                                jsonObject["profit"]);

        return sales;
    }
} // Models