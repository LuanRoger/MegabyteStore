//
// Created by luanr on 19/11/2022.
//

#include "AccountStorage.h"

AccountStorage::AccountStorage(std::vector<Models::Account*> loadedAccount) {
    accounts = loadedAccount;
}

void AccountStorage::AddAccount(Models::Account* account) {
    if(ValideUser(account->getUsername(), account->getPassword()) != nullptr)
        return;

    accounts.push_back(account);
    SaveAccounts();
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
        json accountJsonObject = accounts->ToJson();

        productsArray.push_back(accountJsonObject);
    }

    FileWriter fileWriter(ACCOUNTS_JSON_FILE);
    fileWriter.Start();
    fileWriter.Write(productsArray.dump(4));
    fileWriter.Flush();
}

