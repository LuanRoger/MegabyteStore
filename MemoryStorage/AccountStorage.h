//
// Created by luanr on 19/11/2022.
//

#ifndef MEGABYTESTORE_ACCOUNTSTORAGE_H
#define MEGABYTESTORE_ACCOUNTSTORAGE_H

#include <iostream>
#include <vector>
#include "../Models/Product.h"
#include "../Models/Account.h"
#include "../Services/IOService/FileWriter.h"
#include "../Consts.h"
#include "../Utils/Json/json.hpp"

using namespace IOService;

class AccountStorage {
private:
    std::vector<Models::Account*> accounts;

public:
    AccountStorage() = default;
    AccountStorage(std::vector<Models::Account*> loadedAccount);

    void AddAccount(Models::Account* account);
    Models::Account* ValideUser(string username, string password);

    void SaveAccounts();
};


#endif //MEGABYTESTORE_ACCOUNTSTORAGE_H
