#include <windows.h>
#include "MenuCommands/RegisterProductCommand.h"
#include "Internals/MenuSystem/Menu.h"
#include "MemoryStorage/ProductsStorage.h"
#include "MenuCommands/RegisterClientCommand.h"
#include "MenuCommands/LoginClientCommand.h"
#include "MemoryStorage/AccountStorage.h"
#include "Utils/InfoLoders/AccountsLoader.h"
#include "Utils/InfoLoders/ProductsLoader.h"
#include "Utils/InfoLoders/SalesLoader.h"
#include "MenuCommands/ProductBuyCommand.h"
#include "Controllers/SalesController.h"

using namespace MenuSystem;
using namespace MenuCommand;
using namespace MemoryStorage;
using namespace Loaders;
using namespace Controllers;

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
        Account* tempHolder = command.Execute();
        bool result = accountStorage->AddAccount(tempHolder);

        if(!result) {
            cout << "Este usuario já esta cadastrado." << endl;
            delete tempHolder;
            return;
        }

        currentSessionAccount = tempHolder;
    }));
    loginMenu->AddMenu(MenuInfoItem(0, "Sair", [loginMenu]() {
        loginMenu->Stop();
    }));

    loginMenu->Start([&currentSessionAccount]() -> bool {
        return currentSessionAccount == nullptr;
    });

    return currentSessionAccount;
}

void ShowProductsMenu(ProductsStorage* productsStorage) {
    Menu* productsMenu = new Menu("==Produtos==");
    productsMenu->AddMenu(MenuInfoItem(1, "Ver todos os produtos", [productsStorage]() {
        cout << "------------------------------" << endl;
        for(Product* product : productsStorage->getProducts()) {
            cout << product->ToString() + " x" + to_string(product->getQuantity()) +
                                 " R$ " + to_string(product->getValue()) + "/u" << endl;
        }
        cout << "------------------------------" << endl;
    }));
    productsMenu->AddMenu(MenuInfoItem(2, "Ver produto detalhado", [productsStorage]() {
        LineReader lineReader(ReaderOptions("Digite um valor válido.", false));
        int productId = lineReader.ReadInt("Digite o ID do produto:");
        Product* product = productsStorage->getById(productId);

        if(product == nullptr) {
            cout << "Este produto não existe." << endl;
            return;
        }

        product->View();
    }));
    productsMenu->AddMenu(MenuInfoItem(0, "Voltar.", [&productsMenu]() {  productsMenu->Stop(); }));

    productsMenu->Start();
    delete productsMenu;
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
    delete manageProducts;
}
Menu* BuildAdmMenu(ProductsStorage* productsStorage, SalesController* salesController, Account currentAccount) {
    Menu* menu = new Menu("==MegabyteStore==");
    menu->SetContent("Bem-vindo(a), " + currentAccount.getUsername() + ".");

    menu->AddMenu(MenuInfoItem(1, "Cadastrar produto.",
                               [productsStorage]() {
                                   RegisterProductCommand command;
                                   Product* newProduct = command.Execute();
                                   if(newProduct != nullptr)
                                       productsStorage->AddProduct(newProduct);
                               }));
    menu->AddMenu(MenuInfoItem(2,
                               "Gerenciar produtos.", [productsStorage]()
                               { ShowManageProductsMenu(productsStorage); }));

    menu->AddMenu(MenuInfoItem(3, "Visualizar produtos.", [productsStorage]()
    { ShowProductsMenu(productsStorage); }));
    menu->AddMenu(MenuInfoItem(4, "Salvar no arquivo", [productsStorage, salesController]() {
        FileWriter fileWriter("Relatorio.txt");
        fileWriter.Start();

        //Sales
        fileWriter.WriteLine("Vendas------------------------");
        fileWriter.WriteLine("Item vendidos: " + to_string(salesController->getSoldItems()));
        fileWriter.WriteLine("Lucro: " + to_string(salesController->getProfit()));
        fileWriter.WriteLine("------------------------------");

        for (Product* i: productsStorage->getProducts()) {
            fileWriter.WriteLine("------------------------------");
            fileWriter.WriteLine(i->ToString() + " x" + to_string(i->getQuantity()) +
                                 " R$ " + to_string(i->getValue()) + "/u");
        }
        fileWriter.Flush();
    }));

    menu->AddMenu(MenuInfoItem(0, "Sair.", [menu]()
    {
        menu->Stop();
    }));

    return menu;
}

Menu* BuildClientMenu(ProductsStorage* productsStorage, SalesController* salesController, Account currentAccount) {
    Menu* menu = new Menu("==MegabyteStore==");
    menu->SetContent("Bem-vindo(a), " + currentAccount.getUsername() + ".");

    menu->AddMenu(MenuInfoItem(1, "Iniciar compra.",
                               [productsStorage, salesController]() {
        ProductBuyCommand command(productsStorage, salesController);
        command.Execute();
    }));
    menu->AddMenu(MenuInfoItem(2, "Visualizar produtos.", [productsStorage]()
    { ShowProductsMenu(productsStorage); }));
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
    SalesController salesController(SalesLoader::Load());

    auto* productsStorage = new ProductsStorage(loadedProducts);
    auto* accountStorage = new AccountStorage(loadedAccounts);
    Account* currentAccount = LoginMenu(accountStorage);
    if(currentAccount == nullptr) return 0;

    Menu* mainMenu = currentAccount->getUsername() == "admin" ?
            BuildAdmMenu(productsStorage, &salesController, *currentAccount) :
            BuildClientMenu(productsStorage, &salesController, *currentAccount);

    mainMenu->Start();

    return 0;
}
