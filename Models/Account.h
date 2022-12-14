//
// Created by Caio on 17/11/2022.
//

#ifndef MEGABYTESTORE_ACCOUNT_H
#define MEGABYTESTORE_ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include "Enums/AccountType.h"
#include "../Utils/Json/JsonSerializable.h"
#include "../Utils/Json/json.hpp"
#include "../Utils/Cryptography/bcrypt.h"

using namespace std;
using namespace JsonUtils;
using namespace nlohmann;

namespace Models {
    class Account : public JsonSerializable {
    private:
        string name;
        string username;
        string password;
        AccountType accountType;
    public:
        Account ();
        Account (string name, string username, string password, AccountType accountType);
        string getName();
        string getUsername ();
        string getPassword ();

        json ToJson() override;
        static Account* FromJson(json jsonObject);
    };
}

#endif //MEGABYTESTORE_ACCOUNT_H
