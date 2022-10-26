#include <iostream>

using namespace std;

#include "Internals/MenuSystem/MenuBuilder.h"
#include "MenuCommands/MenuCommand1.h"

using namespace MenuSystem;
using namespace MenuCommand;

int main() {
    MenuBuilder* menuBuilder = new MenuBuilder();
    menuBuilder->SetHeader(new std::string("Megabyte Store"));
    menuBuilder->AddMenu(1, new MenuInfoItem(new std::string("Opção 1"), new MenuCommand1()));

    Menu* menu = menuBuilder->Build();
    delete menuBuilder;

    menu->Start();

    return 0;
}
