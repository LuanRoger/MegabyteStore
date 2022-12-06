//
// Created by luanr on 06/12/2022.
//

#ifndef MEGABYTESTORE_SALESCONTROLLER_H
#define MEGABYTESTORE_SALESCONTROLLER_H

#include "../Models/Sales.h"
#include "../Consts.h"
#include "../Services/IOService/FileWriter.h"

using namespace IOService;

namespace Controllers {

    class SalesController {
    private:
        Models::Sales* sales;

    public:
        explicit SalesController(Models::Sales* sales);
        ~SalesController();

        void IncrementItems(int quantity);
        void IncrementProfit(double quantity);

        void SaveChanges();
    };

} // Controllers

#endif //MEGABYTESTORE_SALESCONTROLLER_H
