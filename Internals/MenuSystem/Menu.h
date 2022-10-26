//
// Created by luanr on 26/10/2022.
//

#ifndef MEGABYTESTORE_MENU_H
#define MEGABYTESTORE_MENU_H

#include "string"
#include "map"
#include "string"
#include "iostream"
#include "MenuInfoItem.h"

namespace MenuSystem {
    //TODO: Made only one. There is another one in MenuBuilder.h
    typedef std::map<int, MenuInfoItem *> MenuMapping;

    class Menu {
    private:
        std::string* header;
        MenuMapping* menuMapping;
        bool running;

        void RunMenu();
        void PrintOptions();

    public:
        Menu(MenuMapping *menuMapping, std::string *header);

        void Start();
        void Stop();
    };

} // MenuSystem

#endif //MEGABYTESTORE_MENU_H
