//
// Created by luanr on 26/10/2022.
//

#include "MenuInfoItem.h"

namespace MenuSystem {

    MenuInfoItem::MenuInfoItem(int optionNumber, std::string text, std::function<void()> action) {
        this->optionNumber = optionNumber;
        this->text = text;
        this->action = action;
    }

    int MenuInfoItem::getOptionNumber() const {
        return optionNumber;
    }

    std::string MenuInfoItem::getText() {
        return text;
    }

    std::function<void()> MenuInfoItem::getAction() {
        return action;
    }
} // MenuSystem