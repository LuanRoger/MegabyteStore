//
// Created by luanr on 19/11/2022.
//

#ifndef MEGABYTESTORE_REGISTERCLIENTCOMMAND_H
#define MEGABYTESTORE_REGISTERCLIENTCOMMAND_H

#include <string>
#include <iostream>
#include "../Utils/Read/LineReader.h"
#include "../Utils/Read/ReaderOptions.h"
#include "../Utils/Cryptography/bcrypt.h"
#include "../MemoryStorage/AccountStorage.h"

using namespace Read;

class RegisterClientCommand {
public:
    Models::Account* Execute();
};


#endif //MEGABYTESTORE_REGISTERCLIENTCOMMAND_H
