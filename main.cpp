#include <iostream>

#include "MenuCommands/MenuCommand1.h"
#include "Internals/MenuSystem/Menu.h"
#include "Internals/MenuSystem/Commands/OpenSubmenuCommand.h"

using namespace std;
using namespace MenuSystem;
using namespace MenuCommand;

int main() {
    Menu* menu = new Menu(new string("MegabyteStore"));

    menu->AddMenu(new MenuInfoItem(1,
                                   new string("Opcao 1"),
                                   new MenuCommand1()));

    Menu* submenu1 = new Menu(new string("Submenu"));
    submenu1->AddEscapeOption(new MenuInfoItem(0, new string("Voltar"),
                                               nullptr, true));
    menu->AddMenu(new MenuInfoItem(2,
                                   new string("Abrir submenu"),
                                   new OpenSubmenuCommand(submenu1)));

    menu->AddEscapeOption(new MenuInfoItem(0,
                                           new string("Sair"),
                                           nullptr,
                                           true));

    menu->Start();

    return 0;
}
