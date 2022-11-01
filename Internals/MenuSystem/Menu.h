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
        string* header;
        string* content = nullptr;
        vector<MenuInfoItem*>* menuMapping;
        bool running;
        int escapeOptionIndex;

        void RunMenu();
        void PrintHeaderContent();
        void PrintOptions();

        void InjectCommandOnEscapeOption();

    public:
        Menu(string* header);
        Menu(string* header, string* content);

        void SetHeader(string* header);
        void SetContent(string* content);
        void AddMenu(MenuInfoItem* menuInfo);
        void AddEscapeOption(MenuInfoItem* menuInfo);

        void Start();
        void Stop();
    };

} // MenuSystem

#endif //MEGABYTESTORE_MENU_H
