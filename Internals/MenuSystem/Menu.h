//
// Created by luanr on 26/10/2022.
//

#ifndef MEGABYTESTORE_MENU_H
#define MEGABYTESTORE_MENU_H

#include "string"
#include "vector"
#include "string"
#include "iostream"
#include "MenuInfoItem.h"

using namespace std;

namespace MenuSystem {
    class Menu {
    private:
        std::string* header;
        vector<MenuInfoItem*>* menuMapping;
        bool running;
        int escapeOptionIndex;

        void RunMenu();
        void PrintOptions();

        void InjectCommandOnEscapeOption();

    public:
        Menu(std::string *header);

        void SetHeader(std::string* header);
        void AddMenu(MenuInfoItem* menuInfo);
        void AddEscapeOption(MenuInfoItem* menuInfo);

        void Start();
        void Stop();
    };

} // MenuSystem

#endif //MEGABYTESTORE_MENU_H
