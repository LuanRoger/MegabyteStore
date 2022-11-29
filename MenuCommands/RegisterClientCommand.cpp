//
// Created by luanr on 19/11/2022.
//

#include "RegisterClientCommand.h"

Models::Account* RegisterClientCommand::Execute() {
    std::string name, username, password;

    LineReader lineReader(ReaderOptions("Digite valores validos.", false));

    name = lineReader.ReadString("Digite seu nome: ");
    username = lineReader.ReadString("Digite seu usuario: ");
    password = lineReader.ReadString("Digite sua senha: ");

    Models::Account* newAccount = new Models::Account(name, username, password, AccountType::CLIENT);
    return newAccount;

}
