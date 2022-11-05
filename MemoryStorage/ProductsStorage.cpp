//
// Created by luanr on 05/11/2022.
//

#include "ProductsStorage.h"

namespace MemoryStorage {
    ProductsStorage::ProductsStorage(std::vector<Models::Product*> loadedProducts) {
        products = loadedProducts;
    }

    void ProductsStorage::AddProduct(Models::Product *product) {
        products.push_back(product);
    }

    void ProductsStorage::RemoveProduct(int index) {
        auto interator = products.begin();

        for (int c = 0; c < index; ++c)
            interator++;

        products.erase(interator);
    }

    void ProductsStorage::Clear() {
        for (Models::Product* product : products)
            delete product;
        products.clear();
    }

    std::vector<Models::Product*> ProductsStorage::getProducts() const {
        return products;
    }


} // MemoryStorage