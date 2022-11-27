//
// Created by luanr on 23/11/2022.
//

#include "ProductsLoader.h"

namespace Loaders {
    std::vector<Models::Product*> ProductsLoader::Load() {
        FileReader fileReader(PRODUCTS_JSON_FILE);
        std::string jsonText = fileReader.ReadAll();

        nlohmann::json j;
        json productsFile = json::parse(jsonText);

        std::vector<Models::Product*> accounts;
        for (const auto& jsonProducts : productsFile) {
            //TODO: Create a product based on her type
        }

        return accounts;
    }
} // Loaders