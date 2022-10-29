#include <iostream>

#include "MenuCommands/MenuCommand1.h"
#include "Internals/MenuSystem/Menu.h"

using namespace std;
using namespace MenuSystem;
using namespace MenuCommand;

int main() {
    Menu* menu = new Menu(new string("MegabyteStore"));
    menu->AddMenu(new MenuInfoItem(1,
                                   new string("Opcao 1"),
                                   new MenuCommand1()));
    menu->AddEscapeOption(new MenuInfoItem(0,
                                           new string("Sair"),
                                           nullptr,
                                           true));

    menu->Start();

    return 0;
}
