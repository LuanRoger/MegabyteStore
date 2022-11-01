//
// Created by luanr on 26/10/2022.
//

#include "Menu.h"
#include "Commands/ExitMenuCommand.h"

namespace MenuSystem {
    Menu::Menu(std::string* header) {
        this->menuMapping = new vector<MenuInfoItem*>;
        this->header = header;
    }
    Menu::Menu(string* header, string* content) {
        this->menuMapping = new vector<MenuInfoItem*>;
        this->header = header;
        this->content = content;
    }

    void Menu::PrintHeaderContent() {
        cout << *header << endl;

        if(content != nullptr)
            cout << *content << endl;
    }
    void Menu::PrintOptions() {
        for (MenuInfoItem* menuInfoItem : *menuMapping) {
            string menuOption =  "[ " + std::to_string(menuInfoItem->getOptionNumber()) + " ] - " +
                    menuInfoItem->getText();
            cout << menuOption << endl;
        }
    }
    void Menu::RunMenu() {
        PrintHeaderContent();

        while (running) {
            int choice;

            PrintOptions();

            cin >> choice;

            IMenuCommand* menuCommand = nullptr;
            for(MenuInfoItem* menuInfoItem : *menuMapping) {
                if(menuInfoItem->getOptionNumber() == choice)
                    menuCommand = menuInfoItem->getCommand();
            }

            if(menuCommand == nullptr) continue;

            menuCommand->Execute();
        }
    }

    void Menu::InjectCommandOnEscapeOption() {
        MenuInfoItem* menuInfo = (*menuMapping)[escapeOptionIndex];
        menuInfo->setCommand(new ExitMenuCommand(this));
    }

    void Menu::AddMenu(MenuInfoItem *menuInfo) {
        menuMapping->push_back(menuInfo);
    }

    void Menu::AddEscapeOption(MenuInfoItem *menuInfo) {
        if(!menuInfo->isEscapeOption())
            throw std::invalid_argument("MenuInfoItem is not a escape option");

        escapeOptionIndex = static_cast<int>(menuMapping->size());
        menuMapping->push_back(menuInfo);
        InjectCommandOnEscapeOption();
    }

    void Menu::SetHeader(std::string *header) {
        this->header = header;
    }
    void Menu::SetContent(string* content) {
        this->content = content;
    }

    void Menu::Start() {
        running = true;
        RunMenu();
    }

    void Menu::Stop() {
        running = false;
    }

} // MenuSystem