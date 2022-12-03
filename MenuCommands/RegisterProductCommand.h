//
// Created by luanr on 26/10/2022.
//

#ifndef MEGABYTESTORE_REGISTERPRODUCTCOMMAND_H
#define MEGABYTESTORE_REGISTERPRODUCTCOMMAND_H

#include <iostream>
#include "../MemoryStorage/ProductsStorage.h"
#include "../Models/CPU.h"
#include "../Models/GPU.h"
#include "../Models/Motherboard.h"
#include "../Models/PowerSupply.h"
#include "../Models/RAMMemory.h"
#include "../Models/StorageUnit.h"
#include "../Models/Product.h"
#include "../Utils/Read/LineReader.h"
#include "../Utils/Read/ReaderOptions.h"
#include "../Internals/MenuSystem/Menu.h"
#include "../Internals/MenuSystem/MenuInfoItem.h"

using namespace Models;
using namespace std;
using namespace Read;
using namespace MenuSystem;

namespace MenuCommand {
    class RegisterProductCommand {
        static Models::CPU* RegistryCPU();
        static Models::GPU* RegistryGPU();
        static Models::Motherboard* RegistryMotherboard();
        static Models::PowerSupply* RegistryPowerSupply();
        static Models::RAMMemory* RegistryRAMMemory();
        static Models::StorageUnit* RegistryStorageUnit();

    public:
        Product* Execute();
    };
}

#endif //MEGABYTESTORE_REGISTERPRODUCTCOMMAND_H
