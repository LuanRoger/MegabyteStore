//
// Created by luanr on 27/11/2022.
//

#include "AccountsLoader.h"

namespace Loaders {
    std::vector<Models::Account*> AccountsLoader::Load() {
        FileReader fileReader(ACCOUNTS_JSON_FILE);
        if(!fileReader.Exists()) {
            std::vector<Models::Account*> emptyVector;
            return emptyVector;
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