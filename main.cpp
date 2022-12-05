#include <windows.h>
#include "MenuCommands/RegisterProductCommand.h"
#include "Internals/MenuSystem/Menu.h"
#include "MemoryStorage/ProductsStorage.h"
#include "MenuCommands/RegisterClientCommand.h"
#include "MenuCommands/LoginClientCommand.h"
#include "MemoryStorage/AccountStorage.h"
#include "Utils/InfoLoders/AccountsLoader.h"
#include "Utils/InfoLoders/ProductsLoader.h"
#include "MenuCommands/ProductBuyCommand.h"

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

void ShowManageProductsMenu(ProductsStorage* productsStorage) {
    Menu* manageProducts = new Menu("==Gerenciar produtos==");
    manageProducts->AddMenu(MenuInfoItem(1, "Adicionar ao estoque", [productsStorage]() {
        LineReader lineReader(ReaderOptions("Digite um valor valido", false));

        int productId = lineReader.ReadInt("Digite o ID do produto que deseja adicionar:");
        int addQuantity = lineReader.ReadInt("Digite quantos deseja adicionar:");
        bool result = productsStorage->IncrementProductById(productId, addQuantity);

        if(!result) {
            cout << "Este produto não existe." << endl;
            return;
        }

        cout << "Estoque atualizado com sucesso" << endl;
    }));
    manageProducts->AddMenu(MenuInfoItem(2, "Remover produto", [productsStorage]() {
        LineReader lineReader(ReaderOptions("Digite um valor valido", false));

        int productId = lineReader.ReadInt("Digite o ID do produto que deseja remover:");
        int removeQuantity = lineReader.ReadInt("Digite quantos deseja remover:");
        bool result = productsStorage->RemoveById(productId, removeQuantity);

        if(!result) {
            cout << "Este produto não existe." << endl;
            return;
        }
        cout << "Produto removido com sucesso" << endl;
    }));
    manageProducts->AddMenu(MenuInfoItem(0, "Voltar", [manageProducts]() { manageProducts->Stop(); }));

    manageProducts->Start();
}
Menu* BuildAdmMenu(ProductsStorage* productsStorage, Account currentAccount) {
    Menu* menu = new Menu("==MegabyteStore==");
    menu->SetContent("Bem-vindo(a), " + currentAccount.getUsername() + ".");

    menu->AddMenu(MenuInfoItem(1, "Cadastrar produto.",
                               [productsStorage]() {
                                   RegisterProductCommand command;
                                   Product* newProduct = command.Execute();
                                   if(newProduct != nullptr)
                                       productsStorage->AddProduct(newProduct);
                               }));

    Menu* manageProducts = new Menu("==Gerenciar produtos==");
    manageProducts->AddMenu(MenuInfoItem(1, "Remover produto", []() {}));
    manageProducts->AddMenu(MenuInfoItem(1, "Alterar estoque", []() {}));
    manageProducts->AddMenu(MenuInfoItem(3, "Salvar no arquivo", [&productsStorage]() {
        FileWriter fileWriter("Relatorio.txt");
        fileWriter.Start();
        for (Product* i: productsStorage->getProducts()) {
            fileWriter.WriteLine("------------------------------");
            fileWriter.WriteLine(to_string(i->getId()));
            fileWriter.WriteLine(to_string(i->getQuantity()));
            fileWriter.WriteLine(to_string(i->getValue()));
        }
        fileWriter.Flush();
    }));
    manageProducts->AddMenu(MenuInfoItem(0, "Voltar", [manageProducts]() { manageProducts->Stop(); }));
    menu->AddMenu(MenuInfoItem(2,
                               "Gerenciar produtos.", [productsStorage]()
                               { ShowManageProductsMenu(productsStorage); }));

    menu->AddMenu(MenuInfoItem(0, "Sair.", [menu]()
    {
        menu->Stop();
    }));

    return menu;
}

Menu* BuildClientMenu(ProductsStorage* productsStorage, Account currentAccount) {
    Menu* menu = new Menu("==MegabyteStore==");
    menu->SetContent("Bem-vindo(a), " + currentAccount.getUsername() + ".");

    menu->AddMenu(MenuInfoItem(1, "Iniciar compra.",
                               [productsStorage]() {
        ProductBuyCommand command(productsStorage);
        command.Execute();
    }));
    menu->AddMenu(MenuInfoItem(0, "Sair.", [menu]()
    {
        menu->Stop();
    }));

    return menu;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    vector<Account*> loadedAccounts = AccountsLoader::Load();
    list<Product*> loadedProducts = ProductsLoader::Load();

    auto* productsStorage = new ProductsStorage(loadedProducts);
    auto* accountStorage = new AccountStorage(loadedAccounts);
    Account* currentAccount = LoginMenu(accountStorage);

    Menu* mainMenu = currentAccount->getUsername() == "admin" ?
            BuildAdmMenu(productsStorage, *currentAccount) :
            BuildClientMenu(productsStorage, *currentAccount);

    mainMenu->Start();

    return 0;
}
