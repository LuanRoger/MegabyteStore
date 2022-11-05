#ifndef MEGABYTESTORE_MENUINFOITEM_H
#define MEGABYTESTORE_MENUINFOITEM_H

#include "string"
#include "Commands/IMenuCommand.h"

namespace MenuSystem {

    class MenuInfoItem {
    private:
        int optionNumber;
        std::string text;
        IMenuCommand* menuCommand;
        bool escapeOption;
    public:
        MenuInfoItem(int optionNumber, std::string text, IMenuCommand* menuCommand, bool escapeOption = false);

        int getOptionNumber() const;
        std::string getText();
        IMenuCommand* getCommand();
        void setCommand(IMenuCommand* command);
        bool isEscapeOption() const;
    };

} // MenuSystem

#endif //MEGABYTESTORE_MENUINFOITEM_H
