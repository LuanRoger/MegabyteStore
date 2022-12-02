//
// Created by luanr on 27/11/2022.
//

#include "AccountsLoader.h"

namespace Loaders {
    std::vector<Models::Account*> AccountsLoader::CreateDefaultAdminAccount() {
        auto* defaultAccount = new Account("admin", "admin", "admin", AccountType::ADM);

        json accounts = json::array();
        accounts.push_back(defaultAccount->ToJson());

        FileWriter jsonWriter(ACCOUNTS_JSON_FILE);
        jsonWriter.Start();
        jsonWriter.Write(accounts.dump(4));
        jsonWriter.Flush();

        return std::vector<Models::Account*> { defaultAccount };
    }

    std::vector<Models::Account*> AccountsLoader::Load() {
        FileReader fileReader(ACCOUNTS_JSON_FILE);
        if(!fileReader.Exists()) {
            return CreateDefaultAdminAccount();
        }

        std::string jsonText = fileReader.ReadAll();

        nlohmann::json j;
        json accountsFile = json::parse(jsonText);

        std::vector<Models::Account*> accounts;
        for (const auto& jsonAccount : accountsFile) {
            accounts.push_back(Account::FromJson(jsonAccount));
        }

        return accounts;
    }
} // Loaders