#include "MenuCommands/RegistryProductCommand.h"
#include "Internals/MenuSystem/Menu.h"
#include "Internals/MenuSystem/Commands/OpenSubmenuCommand.h"
#include "MemoryStorage/ProductsStorage.h"

using namespace std;
using namespace MenuSystem;
using namespace MenuCommand;
using namespace MemoryStorage;

int main() {
    ProductsStorage* productsStorage = new ProductsStorage();

    Menu* menu = new Menu("MegabyteStore");

    menu->AddMenu(new MenuInfoItem(1,
                                   "Cadastrar produto.",
                                   new RegistryProductCommand(productsStorage)));

    Menu* submenu1 = new Menu("Submenu");
    submenu1->AddEscapeOption(new MenuInfoItem(0, "Voltar",
                                               nullptr, true));
    menu->AddMenu(new MenuInfoItem(2,
                                   "Abrir submenu",
                                   new OpenSubmenuCommand(submenu1)));

    menu->AddEscapeOption(new MenuInfoItem(0,
                                           "Sair",
                                           nullptr,
                                           true));
    menu->Start();

    return 0;
}
