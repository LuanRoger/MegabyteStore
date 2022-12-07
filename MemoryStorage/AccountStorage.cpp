//
// Created by luanr on 19/11/2022.
//

#include "AccountStorage.h"

AccountStorage::AccountStorage(std::vector<Models::Account*> loadedAccount) {
    accounts = loadedAccount;
}

bool AccountStorage::AddAccount(Models::Account* account) {
    for (Models::Account* registeredAccount : accounts) {
        if(account->getUsername() == registeredAccount->getUsername())
            return false;
    }

    accounts.push_back(account);
    SaveAccounts();

    return true;
}

Models::Account* AccountStorage::ValideUser(string username, string password) {
    for (int i = 0; i<accounts.size(); i++) {
        if(accounts[i]->getUsername() == username &&
        bcrypt::validatePassword(password, accounts[i]->getPassword())) {
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

std::vector<Models::Account *> AccountStorage::getAccounts() const {
    return accounts;
}

