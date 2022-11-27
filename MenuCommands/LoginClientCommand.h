//
// Created by luanr on 19/11/2022.
//

#ifndef MEGABYTESTORE_LOGINCLIENTCOMMAND_H
#define MEGABYTESTORE_LOGINCLIENTCOMMAND_H

#include "../MemoryStorage/AccountStorage.h"
#include "../Utils/Read/LineReader.h"
#include "../Utils/Read/ReaderOptions.h"

using namespace Read;

class LoginClientCommand {
private:
    AccountStorage* accountStorage;

public:
    LoginClientCommand(AccountStorage* accountStorage);
    Models::Account* Execute();
};


#endif //MEGABYTESTORE_LOGINCLIENTCOMMAND_H
