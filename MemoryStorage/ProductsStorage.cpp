//
// Created by luanr on 05/11/2022.
//

#include "ProductsStorage.h"

namespace MemoryStorage {
    ProductsStorage::ProductsStorage(std::list<Product*> loadedProducts) {
        products = loadedProducts;
    }

    void ProductsStorage::AddProduct(Product *product) {
        products.push_back(product);
        SaveProducts();
    }

    void ProductsStorage::RemoveByOrder(Order order) {
        Product* toRemoveProduct = nullptr;

        for (Product* product : products) {
            if(product->getId() == order.getProductId()) {
                toRemoveProduct = product;
                break;
            }
        }

        if(toRemoveProduct == nullptr) return;

        toRemoveProduct->setQuantity(toRemoveProduct->getQuantity() - order.getQuantity());
        if(toRemoveProduct->getQuantity() <= 0) {
            products.remove(toRemoveProduct);
        }

        SaveProducts();
    }

    void ProductsStorage::SaveProducts() {
        json productsArray = json::array();
        for (Product* product : products) {
            productsArray.push_back(product->ToJson());
        }

        FileWriter fileWriter(PRODUCTS_JSON_FILE);
        fileWriter.Start();
        fileWriter.Write(productsArray.dump(4));
        fileWriter.Flush();
    }

    std::list<Product*> ProductsStorage::getProducts() const {
        return products;
    }
    Product *ProductsStorage::getById(int id) const {
        Product* searchResult = nullptr;
        for (Product* product : products) {
            if(product->getId() == id)
                searchResult = product;
        }

        return searchResult;
    }

} // MemoryStorage