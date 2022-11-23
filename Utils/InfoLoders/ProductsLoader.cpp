//
// Created by luanr on 23/11/2022.
//

#include "ProductsLoader.h"

namespace Loaders {
    ProductsLoader::ProductsLoader(std::string filepath) {
        this->filepath = filepath;
    }

    std::vector<Models::Product *> ProductsLoader::Load() {
        FileReader fileReader(PRODUCTS_JSON_FILE);
        std::string jsonText = fileReader.ReadAll();

        nlohmann::json j;
        j.parse(jsonText);
        //TODO: Check whats return
    }
} // Loaders