//
// Created by luanr on 06/12/2022.
//

#ifndef MEGABYTESTORE_SALES_H
#define MEGABYTESTORE_SALES_H

#include "../Utils/Json/json.hpp"
#include "../Utils/Json/JsonSerializable.h"

using namespace JsonUtils;
using namespace nlohmann;

namespace Models {

    class Sales : public JsonSerializable {
    private:
        int soldItems;
        double profit;

    public:
        Sales(int soldItems, double profit);

        void IncrementItems(int quantity);
        void IncrementProfit(double quantity);

        int getSoldItems();
        double getProfit();

        json ToJson() override;
        static Sales* FromJson(json jsonObject);
    };

} // Models

#endif //MEGABYTESTORE_SALES_H
