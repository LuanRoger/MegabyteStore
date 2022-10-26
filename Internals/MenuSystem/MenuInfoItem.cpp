//
// Created by luanr on 26/10/2022.
//

#include "MenuInfoItem.h"

namespace MenuSystem {

    MenuInfoItem::MenuInfoItem(std::string *text, MenuSystem::IMenuCommand *menuCommand) {
        this->text = text;
        this->menuCommand = menuCommand;
    }
    MenuInfoItem::~MenuInfoItem() {
        delete text;
    }

    void MenuInfoItem::SetSubMenu(MenuSystem::MenuInfoItem *subMenu) {

    }

    std::string MenuInfoItem::getText() {
        return *text;
    }

    IMenuCommand* MenuInfoItem::getCommand() {
        return menuCommand;
    }
} // MenuSystem