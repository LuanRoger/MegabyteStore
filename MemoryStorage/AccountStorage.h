//
// Created by luanr on 19/11/2022.
//

#ifndef MEGABYTESTORE_ACCOUNTSTORAGE_H
#define MEGABYTESTORE_ACCOUNTSTORAGE_H

#include <iostream>
#include <vector>
#include "../Models/Product.h"
#include "../Models/Usuarios/Account.h"

class AccountStorage {
private:
    std::vector<Account*> accounts;

public:
    AccountStorage() = default;
    AccountStorage(std::vector<Account*> loadedAccount);

    void AddAccount(Account* account);
    Account* ValideUser(string username, string password);
};


#endif //MEGABYTESTORE_ACCOUNTSTORAGE_H
