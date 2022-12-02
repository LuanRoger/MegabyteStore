//
// Created by luanr on 27/11/2022.
//

#ifndef MEGABYTESTORE_ACCOUNTSLOADER_H
#define MEGABYTESTORE_ACCOUNTSLOADER_H

#include <string>
#include <vector>
#include <iostream>
#include "../../Models/Account.h"
#include "../../Models/Enums/AccountType.h"
#include "../../Services/IOService/FileReader.h"
#include "../../Services/IOService/FileWriter.h"
#include "../Json/json.hpp"
#include "../../Consts.h"

using namespace Models;
using namespace IOService;
using namespace nlohmann;

namespace Loaders {

    class AccountsLoader {
    private:
        static std::vector<Models::Account*> CreateDefaultAdminAccount();

    public:
        static std::vector<Models::Account*> Load();
    };

} // Loaders

#endif //MEGABYTESTORE_ACCOUNTSLOADER_H
