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
        json productsFile = json::parse(jsonText);

        std::list<Models::Product*> products;
        for (const auto& jsonProduct : productsFile) {
            switch ((int)jsonProduct["type"]) {
                case ProductType::CPUTYPE:
                    products.push_back(CPU::FromJson(jsonProduct));
                    break;
                case ProductType::GPUTYPE:
                    products.push_back(GPU::FromJson(jsonProduct));
                    break;
                case ProductType::MOTHERBOARDTYPE:
                    products.push_back(Motherboard::FromJson(jsonProduct));
                    break;
                case ProductType::POWERSUPPLYTYPE:
                    products.push_back(PowerSupply::FromJson(jsonProduct));
                    break;
                case ProductType::RAMMEMORYTYPE:
                    products.push_back(RAMMemory::FromJson(jsonProduct));
                    break;
                case ProductType::STORAGEUNITTYPE:
                    products.push_back(StorageUnit::FromJson(jsonProduct));
                    break;
            }
        }

        return products;
    }
} // Loaders