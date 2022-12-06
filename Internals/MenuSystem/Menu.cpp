//
// Created by luanr on 26/10/2022.
//

#include "Menu.h"

namespace MenuSystem {
    Menu::Menu(std::string header) {
        this->header = header;
    }
    Menu::Menu(std::string header, std::string content) {
        this->header = header;
        this->content = content;
    }

    void Menu::PrintHeaderContent() {
        std::cout << header << std::endl;

        if(!content.empty())
            std::cout << content << std::endl;
    }
    void Menu::PrintOptions() {
        for (MenuInfoItem menuInfoItem : menuMapping) {
            std::string menuOption =  "[ " + std::to_string(menuInfoItem.getOptionNumber()) + " ] - " +
                    menuInfoItem.getText();
            std::cout << menuOption << std::endl;
        }
    }
    void Menu::RunMenu(MenuPredictor menuPredictor) {
        LineReader lineReader(ReaderOptions("Digite uma value válido", false));

        do {
            int choice;

            PrintHeaderContent();
            PrintOptions();

            choice = lineReader.ReadInt("Escolha uma opção: ");

            MenuInfoItem* menuCommandInfo = nullptr;
            for(MenuInfoItem menuInfoItem : menuMapping) {
                if(menuInfoItem.getOptionNumber() == choice) {
                    menuCommandInfo = &menuInfoItem;
                    break;
                }
            }

            if(menuCommandInfo == nullptr) continue;

            menuCommandInfo->getAction()();

            if(menuCommandInfo->getPersistResult())
                ClearResult();
            running = menuPredictor();
        }
        while (running);
    }
    void Menu::RunMenu() {
        LineReader lineReader(ReaderOptions("Digite uma value válido", false));

        while (running) {
            int choice;

            PrintHeaderContent();
            PrintOptions();

            choice = lineReader.ReadInt("Escolha uma opção: ");

            MenuInfoItem* menuCommandInfo = nullptr;
            for(MenuInfoItem menuInfoItem : menuMapping) {
                if(menuInfoItem.getOptionNumber() == choice) {
                    menuCommandInfo = &menuInfoItem;
                    break;
                }
            }

            if(menuCommandInfo == nullptr) continue;

            menuCommandInfo->getAction()();

            if(menuCommandInfo->getPersistResult())
                ClearResult();
        }
    }

    void Menu::AddMenu(MenuInfoItem menuInfo) {
        menuMapping.push_back(menuInfo);
    }

    void Menu::SetHeader(std::string header) {
        this->header = header;
    }
    void Menu::SetContent(std::string content) {
        this->content = content;
    }
    void Menu::SetOnMenuStop(std::function<void()> onMenuStop) {
        this->onMenuStop = onMenuStop;
    }

    void Menu::Start(MenuPredictor menuPredictor) {
        RunMenu(menuPredictor);
    }
    void Menu::Start() {
        RunMenu();
    }

    void Menu::Stop() {
        if(onMenuStop != nullptr)
            onMenuStop();

        running = false;
    }

    void Menu::ClearResult() {
        if(system("cls") != 0)
            system("clear");
    }

} // MenuSystem