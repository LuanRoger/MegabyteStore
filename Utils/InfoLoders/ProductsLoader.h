//
// Created by luanr on 23/11/2022.
//

#ifndef MEGABYTESTORE_PRODUCTSLOADER_H
#define MEGABYTESTORE_PRODUCTSLOADER_H

#include <string>
#include <vector>
#include "../../Models/Product.h"
#include "../json.hpp"
#include "../../Services/IOService/FileReader.h"
#include "../../Consts.h"

using namespace IOService;

namespace Loaders {

    class ProductsLoader {
    private:
        std::string filepath;

    public:
        ProductsLoader(std::string filepath);

        std::vector<Models::Product*> Load();
    };

} // Loaders

#endif //MEGABYTESTORE_PRODUCTSLOADER_H
