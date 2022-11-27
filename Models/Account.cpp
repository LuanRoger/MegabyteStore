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

    json Account::ToJson() {
        json jsonAccount;
        jsonAccount = {
                {"name", name},
                {"username", username},
                {"password", password},
                {"type", accountType}
        };

        return jsonAccount;
    }

    Account* Account::FromJson(json jsonObject) {
        auto* account = new Account(jsonObject["name"], jsonObject["username"], jsonObject["password"], jsonObject["type"]);

        return account;
    }
}