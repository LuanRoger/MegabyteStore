//
// Created by luanr on 06/12/2022.
//

#include "SalesController.h"

namespace Controllers {
    SalesController::SalesController(Models::Sales *sales) {
        this->sales = sales;
    }

    SalesController::~SalesController() {
        delete sales;
    }

    void SalesController::IncrementItems(int quantity) {
        sales->setSoldItems(sales->getSoldItems() + quantity);
    }

    void SalesController::IncrementProfit(double quantity) {
        sales->setProfit(sales->getProfit() + quantity);
    }

    void SalesController::SaveChanges() {
        json salesJson = sales->ToJson();

        FileWriter fileWriter(SALES_JSON_FILE);
        fileWriter.Start();
        fileWriter.Write(salesJson.dump(4));
        fileWriter.Flush();
    }
} // Controllers