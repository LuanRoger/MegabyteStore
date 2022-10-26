//
// Created by luanr on 26/10/2022.
//

#include "Menu.h"

namespace MenuSystem {
    Menu::Menu(MenuSystem::MenuMapping* menuMapping, std::string* header) {
        this->menuMapping = menuMapping;
        this->header = header;
    }

    void Menu::PrintOptions() {
        for (auto const&[key, value] : *menuMapping) {
            std::string menuOption =  "[ " + std::to_string(key) + " ] - " + value->getText();
            std::cout << menuOption << std::endl;
        }
    }
    void Menu::RunMenu() {
        std::cout << *header << std::endl;

        while (running) {
            int choice;

            PrintOptions();

            std::cin >> choice;

            IMenuCommand* menuCommand = (*menuMapping)[choice]->getCommand();
            menuCommand->Execute();
        }
    }

    void Menu::Start() {
        running = true;
        RunMenu();
    }

    void Menu::Stop() {
        running = false;
    }

} // MenuSystem