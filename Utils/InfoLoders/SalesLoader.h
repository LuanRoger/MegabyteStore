//
// Created by luanr on 06/12/2022.
//

#ifndef MEGABYTESTORE_SALESLOADER_H
#define MEGABYTESTORE_SALESLOADER_H

#include <string>
#include "../../Models/Sales.h"
#include "../../Services/IOService/FileReader.h"
#include "../../Consts.h"
#include "../Json/json.hpp"

using namespace IOService;
using namespace nlohmann;

namespace Loaders {

    class SalesLoader {
    public:
        static Models::Sales* Load();
    };

} // Loaders

#endif //MEGABYTESTORE_SALESLOADER_H
