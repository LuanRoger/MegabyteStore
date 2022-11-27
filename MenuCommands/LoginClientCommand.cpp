//
// Created by luanr on 19/11/2022.
//

#include "LoginClientCommand.h"

LoginClientCommand::LoginClientCommand(AccountStorage* accountStorage) {
    this->accountStorage = accountStorage;
}

Models::Account* LoginClientCommand::Execute() {
    string username, password;
    LineReader lineReader(ReaderOptions("Digite um valor valido.", false));

    username = lineReader.ReadString("Digite seu usuario:");
    password = lineReader.ReadString("Digite sua senha: ");

    Models::Account* validatedUser = accountStorage->ValideUser(username, password);

    return validatedUser;
}
