//
// Created by luanr on 06/12/2022.
//

#include "SalesLoader.h"

namespace Loaders {
    Models::Sales* SalesLoader::Load() {
        FileReader fileReader(SALES_JSON_FILE);
        if(!fileReader.Exists()) {
            return new Models::Sales(0, 0);
        }

        std::string jsonText = fileReader.ReadAll();

        json salesObject = json::parse(jsonText);
        return Models::Sales::FromJson(salesObject);
    }
} // Loaders