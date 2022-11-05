//
// Created by luanr on 05/11/2022.
//

#ifndef MEGABYTESTORE_MEMORYSTORAGECONTROLLER_H
#define MEGABYTESTORE_MEMORYSTORAGECONTROLLER_H

#include "../MemoryStorage/ProductsStorage.h"
#include "../Models/CPU.h"
#include <vector>

namespace Controllers {

    class MemoryStorageController {
    private:
        MemoryStorage::ProductsStorage* productsStorage;
    public:
        MemoryStorageController(MemoryStorage::ProductsStorage* productsStorage);

        std::vector<Models::CPU*> GetAllCpus();
    };

} // Controllers

#endif //MEGABYTESTORE_MEMORYSTORAGECONTROLLER_H
