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
        SaveProducts();
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

    void ProductsStorage::SaveProducts() {
        json productsArray = json::array();
        for (Models::Product* product : products) {
            productsArray.push_back(product->ToJson());
        }

        FileWriter fileWriter(PRODUCTS_JSON_FILE);
        fileWriter.Start();
        fileWriter.Write(productsArray.dump(4));
        fileWriter.Flush();
    }


} // MemoryStorage