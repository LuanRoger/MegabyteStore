//
// Created by luanr on 29/11/2022.
//

#ifndef MEGABYTESTORE_PRODUCTBUYCOMMAND_H
#define MEGABYTESTORE_PRODUCTBUYCOMMAND_H

#include <iostream>
#include <sstream>
#include "../Models/Cart.h"
#include "../Internals/MenuSystem/Menu.h"
#include "../Internals/MenuSystem/MenuInfoItem.h"
#include "../Models/Product.h"
#include "../Utils/Read/LineReader.h"
#include "../Utils/Read/ReaderOptions.h"
#include "../MemoryStorage/ProductsStorage.h"
#include "../Consts.h"

using namespace Read;
using namespace MenuSystem;

namespace MenuCommand {

    class ProductBuyCommand {
    private:
        Models::Cart cart;
        MemoryStorage::ProductsStorage* productsStorage;
        bool finish = false;

        void ShowAllProducts();
        void ShowCartItems();
        void Checkout();
        void UpdateStorage();
    public:
        ProductBuyCommand(MemoryStorage::ProductsStorage* productsStorage);
        void Execute();

    };

} // MenuCommand

#endif //MEGABYTESTORE_PRODUCTBUYCOMMAND_H
