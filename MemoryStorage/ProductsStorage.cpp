//
// Created by luanr on 05/11/2022.
//

#include "ProductsStorage.h"

namespace MemoryStorage {
    ProductsStorage::ProductsStorage(std::list<Product*> loadedProducts) {
        products = loadedProducts;
    }

    int ProductsStorage::getHeigherId() {
        int heigher = 0;
        for (Product* product : products) {
            if(product->getId() > heigher)
                heigher = product->getId();
        }

        return heigher;
    }

    void ProductsStorage::AddProduct(Product *product) {
        product->setId(getHeigherId() + 1);

        products.push_back(product);
        SaveProducts();
    }
    bool ProductsStorage::IncrementProductById(int id, int quantity) {
        Product* toUpdateProduct = nullptr;

        for (Product* product : products) {
            if(product->getId() == id) {
                toUpdateProduct = product;
                break;
            }
        }

        if(toUpdateProduct == nullptr) return false;

        toUpdateProduct->setQuantity(toUpdateProduct->getQuantity() + quantity);
        SaveProducts();
        return true;
    }

    bool ProductsStorage::RemoveByOrder(Order order) {
        Product* toRemoveProduct = nullptr;

        for (Product* product : products) {
            if(product->getId() == order.getProductId()) {
                toRemoveProduct = product;
                break;
            }
        }

        if(toRemoveProduct == nullptr) return false;

        toRemoveProduct->setQuantity(toRemoveProduct->getQuantity() - order.getQuantity());
        if(toRemoveProduct->getQuantity() <= 0) {
            products.remove(toRemoveProduct);
        }

        SaveProducts();
        return true;
    }
    bool ProductsStorage::RemoveById(int id, int quantity) {
        Product* toRemoveProduct = nullptr;

        for (Product* product : products) {
            if(product->getId() == id) {
                toRemoveProduct = product;
                break;
            }
        }

        if(toRemoveProduct == nullptr) return false;

        toRemoveProduct->setQuantity(toRemoveProduct->getQuantity() - quantity);
        if(toRemoveProduct->getQuantity() <= 0) {
            products.remove(toRemoveProduct);
        }

        SaveProducts();
        return true;
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