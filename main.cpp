#include "MenuCommands/RegistryProductCommand.h"
#include "Internals/MenuSystem/Menu.h"
#include "MemoryStorage/ProductsStorage.h"
#include "MenuCommands/RegisterClientCommand.h"
#include "MenuCommands/LoginClientCommand.h"
#include "MemoryStorage/AccountStorage.h"

using namespace std;
using namespace MenuSystem;
using namespace MenuCommand;
using namespace MemoryStorage;

Account* LoginMenu(AccountStorage* accountStorage) {
    Account* currentSessionAccount;

    Menu* loginMenu = new Menu("-- LOGIN --", "O que deseja fazer:");
    loginMenu->AddMenu(MenuInfoItem(1, "Entrar", [&accountStorage, &currentSessionAccount]() mutable
    {
        LoginClientCommand command(accountStorage);
        currentSessionAccount = command.Execute();
    }));
    loginMenu->AddMenu(MenuInfoItem(2, "Cadastrar cliente", [&currentSessionAccount]() mutable
    {
        RegisterClientCommand command;
        currentSessionAccount = command.Execute();
    }));

    loginMenu->Start([&currentSessionAccount]() -> bool {
        return currentSessionAccount == nullptr;
    });

    return currentSessionAccount;
}

int main() {
    ProductsStorage* productsStorage = new ProductsStorage();
    AccountStorage* accountStorage = new AccountStorage();

    accountStorage->AddAccount(LoginMenu(accountStorage));

    Menu* menu = new Menu("MegabyteStore");

    menu->AddMenu(MenuInfoItem(1, "Cadastrar produto.",
                               [&productsStorage]() {
                                   RegistryProductCommand command;
                                   Product* newProduct = command.Execute();
                                   if(newProduct != nullptr)
                                       productsStorage->AddProduct(newProduct);
                                }));

    Menu* submenu1 = new Menu("Submenu");
    submenu1->AddMenu(MenuInfoItem(0, "Voltar", [submenu1]() { submenu1->Stop(); }));
    menu->AddMenu(MenuInfoItem(2,
                                   "Abrir submenu", [&submenu1]() { submenu1->Start(); }));

    menu->AddMenu(MenuInfoItem(0, "Sair", [menu, productsStorage]()
    {
        productsStorage->SaveProducts();
        menu->Stop();
    }));
    menu->Start();

    return 0;
}
