//
// Created by luanr on 26/10/2022.
//

#ifndef MEGABYTESTORE_REGISTRYPRODUCTCOMMAND_H
#define MEGABYTESTORE_REGISTRYPRODUCTCOMMAND_H

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

using namespace Models;
using namespace std;
using namespace Read;

namespace MenuCommand {
    class RegistryProductCommand {
        static Models::CPU* RegistryCPU();
        Models::GPU* RegistryGPU();
        Models::Motherboard* RegistryMotherboard();
        Models::PowerSupply* RegistryPowerSupply();
        Models::RAMMemory* RegistryRAMMemory();
        Models::StorageUnit* RegistryStorageUnit();

    public:
        Product* Execute();
    };
}

#endif //MEGABYTESTORE_REGISTRYPRODUCTCOMMAND_H
