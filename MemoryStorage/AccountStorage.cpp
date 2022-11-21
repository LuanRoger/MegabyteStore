//
// Created by luanr on 19/11/2022.
//

#include "AccountStorage.h"

AccountStorage::AccountStorage(std::vector<Account*> loadedAccount) {
    accounts = loadedAccount;
}

void AccountStorage::AddAccount(Account* account) {
    accounts.push_back(account);
}

Account* AccountStorage::ValideUser(string username, string password) {
    for (int i = 0; i<accounts.size(); i++) {
        if(accounts[i]->getUsername()==username && accounts[i]->getPassword() == password) {
            return accounts[i];
        }
    }
    return nullptr;
}