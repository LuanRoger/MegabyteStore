#include "MenuCommands/RegistryProductCommand.h"
#include "Internals/MenuSystem/Menu.h"
#include "MemoryStorage/ProductsStorage.h"
#include "MenuCommands/RegisterClientCommand.h"
#include "MenuCommands/LoginClientCommand.h"
#include "MemoryStorage/AccountStorage.h"
#include "Utils/InfoLoders/AccountsLoader.h"

using namespace std;
using namespace MenuSystem;
using namespace MenuCommand;
using namespace MemoryStorage;
using namespace Loaders;

Account* LoginMenu(AccountStorage* accountStorage) {
    Account* currentSessionAccount = nullptr;

    Menu* loginMenu = new Menu("-- LOGIN --", "O que deseja fazer:");
    loginMenu->AddMenu(MenuInfoItem(1, "Entrar", [accountStorage, &currentSessionAccount]() mutable
    {
        LoginClientCommand command(accountStorage);
        Account* tempHolder = command.Execute();
        if(tempHolder != nullptr)
            currentSessionAccount = tempHolder;
        else cout << "Nome de usuario ou senha inválidos." << endl;
    }));
    loginMenu->AddMenu(MenuInfoItem(2, "Cadastrar cliente", [accountStorage, &currentSessionAccount]() mutable
    {
        RegisterClientCommand command;
        currentSessionAccount = command.Execute();
        accountStorage->AddAccount(currentSessionAccount);
    }));

    loginMenu->Start([&currentSessionAccount]() -> bool {
        return currentSessionAccount == nullptr;
    });

    return currentSessionAccount;
}

Menu* BuildAdmMenu(ProductsStorage* productsStorage) {
    Menu* menu = new Menu("==MegabyteStore==");

    menu->AddMenu(MenuInfoItem(1, "Cadastrar produto.",
                               [&productsStorage]() {
                                   RegistryProductCommand command;
                                   Product* newProduct = command.Execute();
                                   if(newProduct != nullptr)
                                       productsStorage->AddProduct(newProduct);
                               }));

    Menu* manageProducts = new Menu("==Gerenciar produtos==");
    manageProducts->AddMenu(MenuInfoItem(1, "Remover produto", []() {}));
    manageProducts->AddMenu(MenuInfoItem(1, "Alterar estoque", []() {}));
    manageProducts->AddMenu(MenuInfoItem(0, "Voltar", [manageProducts]() { manageProducts->Stop(); }));
    menu->AddMenu(MenuInfoItem(2,
                               "Gerenciar produtos", [&manageProducts]() { manageProducts->Start(); }));

    menu->AddMenu(MenuInfoItem(0, "Sair", [menu, productsStorage]()
    {
        productsStorage->SaveProducts();
        menu->Stop();
    }));

    return menu;
}
Menu* BuildClientMenu(ProductsStorage productsStorage, Account currentAccount) {
    Menu* menu = new Menu("==MegabyteStore==");
    menu->SetContent("Bem-vindo(a), " + currentAccount.getUsername() + ".");

    menu->AddMenu(MenuInfoItem(1, "Iniciar compra",
                               []() {
        cout << "Não implementado ainda." << endl;
    }));
    menu->AddMenu(MenuInfoItem(0, "Sair", [menu]()
    {
        menu->Stop();
    }));

    return menu;
}

int main() {
    vector<Account*> loadedAccounts = AccountsLoader::Load();

    auto* productsStorage = new ProductsStorage();
    auto* accountStorage = new AccountStorage(loadedAccounts);
    Account* currentAccount = LoginMenu(accountStorage);

    Menu* mainMenu = currentAccount->getUsername() == "admin" ?
            BuildAdmMenu(productsStorage) :
            BuildClientMenu(*productsStorage, *currentAccount);

    mainMenu->Start();

    return 0;
}
