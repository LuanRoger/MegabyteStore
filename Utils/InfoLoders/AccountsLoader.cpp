//
// Created by luanr on 27/11/2022.
//

#include "AccountsLoader.h"

namespace Loaders {
    std::vector<Models::Account*> AccountsLoader::Load() {
        FileReader fileReader(ACCOUNTS_JSON_FILE);
        std::string jsonText = fileReader.ReadAll();

        nlohmann::json j;
        json accountsFile = json::parse(jsonText);

        std::vector<Models::Account*> accounts;
        for (const auto& jsonAccount : accountsFile) {
            accounts.push_back(Models::Account::FromJson(jsonAccount));
        }

        return accounts;
    }
} // Loaders