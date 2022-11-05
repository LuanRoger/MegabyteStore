//
// Created by luanr on 26/10/2022.
//

#include "MenuInfoItem.h"

namespace MenuSystem {

    MenuInfoItem::MenuInfoItem(int optionNumber, std::string text, MenuSystem::IMenuCommand *menuCommand, bool escapeOption) {
        this->optionNumber = optionNumber;
        this->text = text;
        this->menuCommand = menuCommand;
        this->escapeOption = escapeOption;
    }

    int MenuInfoItem::getOptionNumber() const {
        return optionNumber;
    }

    std::string MenuInfoItem::getText() {
        return text;
    }

    IMenuCommand* MenuInfoItem::getCommand() {
        return menuCommand;
    }
    void MenuInfoItem::setCommand(IMenuCommand* command) {
        this->menuCommand = command;
    }
    bool MenuInfoItem::isEscapeOption() const {
        return escapeOption;
    }
} // MenuSystem