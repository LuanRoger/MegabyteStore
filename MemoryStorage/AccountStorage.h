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
#include "../Utils/Cryptography/bcrypt.h"

using namespace IOService;

class AccountStorage {
private:
    std::vector<Models::Account*> accounts;

public:
    AccountStorage(std::vector<Models::Account*> loadedAccount);

    bool AddAccount(Models::Account* account);
    Models::Account* ValideUser(string username, string password);

    std::vector<Models::Account*> getAccounts() const;

    void SaveAccounts();
};


#endif //MEGABYTESTORE_ACCOUNTSTORAGE_H
