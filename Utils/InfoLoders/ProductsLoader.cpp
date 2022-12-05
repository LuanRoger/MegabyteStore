//
// Created by luanr on 23/11/2022.
//

#include "ProductsLoader.h"

namespace Loaders {
    std::list<Models::Product*> ProductsLoader::Load() {
        FileReader fileReader(PRODUCTS_JSON_FILE);
        if(!fileReader.Exists()) {
            std::list<Models::Product*> emptyList;
            return emptyList;
        }

        std::string jsonText = fileReader.ReadAll();

        nlohmann::json j;
        json productsFile = json::parse(jsonText);

        std::list<Models::Product*> products;
        for (const auto& jsonProducts : productsFile) {
            switch ((int)jsonProducts["type"]) {
                case ProductType::CPUTYPE:
                    products.push_back(CPU::FromJson(jsonProducts));
                    break;
                case ProductType::GPUTYPE:
                    products.push_back(GPU::FromJson(jsonProducts));
                    break;
                case ProductType::MOTHERBOARDTYPE:
                    products.push_back(Motherboard::FromJson(jsonProducts));
                    break;
                case ProductType::POWERSUPPLYTYPE:
                    products.push_back(PowerSupply::FromJson(jsonProducts));
                    break;
                case ProductType::RAMMEMORYTYPE:
                    products.push_back(RAMMemory::FromJson(jsonProducts));
                    break;
                case ProductType::STORAGEUNITTYPE:
                    products.push_back(StorageUnit::FromJson(jsonProducts));
                    break;
            }
        }

        return products;
    }
} // Loaders