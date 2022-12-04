//
// Created by luanr on 23/11/2022.
//

#ifndef MEGABYTESTORE_PRODUCTSLOADER_H
#define MEGABYTESTORE_PRODUCTSLOADER_H

#include <string>
#include <list>
#include "../../Models/Product.h"
#include "../../Models/CPU.h"
#include "../../Models/GPU.h"
#include "../../Models/Motherboard.h"
#include "../../Models/PowerSupply.h"
#include "../../Models/RAMMemory.h"
#include "../../Models/StorageUnit.h"
#include "../Json/json.hpp"
#include "../../Services/IOService/FileReader.h"
#include "../../Consts.h"
#include "../../Models/Enums/ProductType.h"

using namespace IOService;
using namespace Models;

namespace Loaders {

    class ProductsLoader {
    public:
        static std::list<Models::Product*> Load();
    };

} // Loaders

#endif //MEGABYTESTORE_PRODUCTSLOADER_H
