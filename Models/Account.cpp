//
// Created by Caio on 17/11/2022.
//

#include "Account.h"

namespace Models {
    Account::Account () {
        name = "";
        username = "";
        password = "";
        accountType = AccountType::CLIENT;
    }

    Account::Account (string name, string username, string password, AccountType accountType) {
        this->name = name;
        this->username = username;
        this->password = password;
        this->accountType = accountType;
    }
    string Account::getUsername () {
        return username;
    }

    string Account::getPassword () {
        return password;
    }

    std::string Account::ToJson() {
        json jsonAccount;
        jsonAccount = {
                {"name", name},
                {"username", username},
                {"password", password},
                {"type", accountType}
        };

        return jsonAccount.dump();
    }

    Account* Account::FromJson(std::string jsonText) {
        json j = json::parse(jsonText);
        Account* account = new Account(j["name"], j["username"], j["password"], j["type"]);

        return account;
    }
}