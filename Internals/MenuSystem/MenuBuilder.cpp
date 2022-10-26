#include "MenuBuilder.h"

namespace MenuSystem {
    MenuBuilder::MenuBuilder() {
        menuMapping = new MenuMapping();
    }

    void MenuBuilder::SetHeader(std::string *header) {
        this->header = header;
    }

    void MenuBuilder::AddMenu(int optionIndex, MenuSystem::MenuInfoItem *menuInfo) {
        menuMapping->insert(std::pair<int, MenuInfoItem*>(optionIndex, menuInfo));
    }

    MenuSystem::Menu* MenuBuilder::Build() {
        return new Menu(menuMapping, header);
    }
}