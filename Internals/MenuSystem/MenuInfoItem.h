#ifndef MEGABYTESTORE_MENUINFOITEM_H
#define MEGABYTESTORE_MENUINFOITEM_H

#include "string"
#include "IMenuCommand.h"

namespace MenuSystem {

    class MenuInfoItem {
    private:
        std::string* text;
        IMenuCommand* menuCommand;
    public:
        ~MenuInfoItem();
        MenuInfoItem(std::string* text, IMenuCommand* menuCommand);

        void SetSubMenu(MenuInfoItem* subMenu);
        std::string getText();
        IMenuCommand* getCommand();
    };

} // MenuSystem

#endif //MEGABYTESTORE_MENUINFOITEM_H
