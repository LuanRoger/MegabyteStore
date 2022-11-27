//
// Created by luanr on 19/11/2022.
//

#include "AccountStorage.h"

AccountStorage::AccountStorage(std::vector<Models::Account*> loadedAccount) {
    accounts = loadedAccount;
}

void AccountStorage::AddAccount(Models::Account* account) {
    accounts.push_back(account);
}

Models::Account* AccountStorage::ValideUser(string username, string password) {
    for (int i = 0; i<accounts.size(); i++) {
        if(accounts[i]->getUsername()==username && accounts[i]->getPassword() == password) {
            return accounts[i];
        }
    }
    return nullptr;
}

void AccountStorage::SaveAccounts() {
    json productsArray = json::array();
    for (Models::Account* accounts : accounts) {
        productsArray.push_back(accounts->ToJson());
    }

    FileWriter fileWriter(PRODUCTS_JSON_FILE);
    fileWriter.Start();
    fileWriter.Write(productsArray.dump(4));
    fileWriter.Flush();
}

