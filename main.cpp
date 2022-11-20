#include "MenuCommands/RegistryProductCommand.h"
#include "Internals/MenuSystem/Menu.h"
#include "MemoryStorage/ProductsStorage.h"
#include "MenuCommands/RegisterClientCommand.h"
#include "MenuCommands/LoginClientCommand.h"
#include "MemoryStorage/AccountStorage.h"
#include "MenuCommands/LoginAdmCommand.h"

using namespace std;
using namespace MenuSystem;
using namespace MenuCommand;
using namespace MemoryStorage;

Account* LoginMenu(AccountStorage* accountStorage) {
    Account* currentSessionAccount = nullptr;

    Menu* loginMenu = new Menu("-- LOGIN --", "O que deseja fazer:");
    loginMenu->AddMenu(MenuInfoItem(1, "Cadastrar cliente", [&currentSessionAccount]() {
        RegisterClientCommand command;
        currentSessionAccount = command.Execute();
    }));

    Menu* submenuLogin = new Menu("-- ENTRAR --", "Como deseja entrar?");
    submenuLogin->AddMenu(MenuInfoItem(1, "Admin", []() { LoginClientCommand command; command.Execute(); }));
    submenuLogin->AddMenu(MenuInfoItem(2, "Client", []() { LoginClientCommand command; command.Execute(); }));
    submenuLogin->AddEscapeOption(MenuInfoItem(0, "Voltar", nullptr, true));

    loginMenu->AddMenu(MenuInfoItem(2, "Entrar", [&submenuLogin]() { submenuLogin->Start(); }));

    loginMenu->Start([currentSessionAccount]() -> bool {
        return currentSessionAccount == nullptr;
    });

    return currentSessionAccount;
}

int main() {
    ProductsStorage* productsStorage = new ProductsStorage();
    AccountStorage* accountStorage = new AccountStorage();

    LoginMenu(accountStorage);

    Menu* menu = new Menu("MegabyteStore");

    menu->AddMenu(MenuInfoItem(1, "Cadastrar produto.",
                               [&productsStorage]() {
                                   RegistryProductCommand command;
                                   Product* newProduct = command.Execute();
                                   if(newProduct != nullptr)
                                       productsStorage->AddProduct(newProduct);
                                }));

    Menu* submenu1 = new Menu("Submenu");
    submenu1->AddEscapeOption(MenuInfoItem(0, "Voltar", nullptr, true));
    menu->AddMenu(MenuInfoItem(2,
                                   "Abrir submenu", [&submenu1]() { submenu1->Start(); }));

    menu->AddEscapeOption(MenuInfoItem(0, "Sair", nullptr, true));
    menu->Start();

    return 0;
}
