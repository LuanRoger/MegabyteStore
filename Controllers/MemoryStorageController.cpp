//
// Created by luanr on 05/11/2022.
//

#include "MemoryStorageController.h"

namespace Controllers {
    MemoryStorageController::MemoryStorageController(MemoryStorage::ProductsStorage *productsStorage) {
        this->productsStorage = productsStorage;
    }

    std::vector<Models::CPU*> MemoryStorageController::GetAllCpus() {
        std::vector<Models::CPU*> cpuBuffer;

        for (Models::Product* product : productsStorage->getProducts()) {
            auto typeCpu = typeid(Models::CPU*).name();
            auto typeProduct = typeid(*product).name();
            if(typeProduct == typeCpu)
                cpuBuffer.push_back(static_cast<Models::CPU*>(product));
        }

        return cpuBuffer;
    }
} // Controllers