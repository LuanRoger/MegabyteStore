//
// Created by luanr on 05/11/2022.
//

#ifndef MEGABYTESTORE_PRODUCTSSTORAGE_H
#define MEGABYTESTORE_PRODUCTSSTORAGE_H

#include <list>
#include "../Models/Product.h"
#include "../Models/Order.h"
#include "../Services/IOService/FileWriter.h"
#include "../Consts.h"
#include "../Utils/Json/json.hpp"

using namespace IOService;
using namespace Models;
using namespace nlohmann;

namespace MemoryStorage {

    class ProductsStorage {
    private:
        std::list<Product*> products;

    public:
        ProductsStorage() = default;
        ProductsStorage(std::list<Product*> loadedProducts);

        void AddProduct(Product* product);
        void RemoveByOrder(Order order);
        void SaveProducts();

        std::list<Product*> getProducts() const;
        Product* getById(int id) const;
    };

} // MemoryStorage

#endif //MEGABYTESTORE_PRODUCTSSTORAGE_H
