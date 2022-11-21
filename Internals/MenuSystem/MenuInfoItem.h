#ifndef MEGABYTESTORE_MENUINFOITEM_H
#define MEGABYTESTORE_MENUINFOITEM_H

#include <string>
#include <functional>

namespace MenuSystem {

    class MenuInfoItem {
    private:
        int optionNumber;
        std::string text;
        std::function<void()> action;
    public:
        MenuInfoItem(int optionNumber, std::string text, std::function<void()> action);

        int getOptionNumber() const;
        std::string getText();
        std::function<void()> getAction();
    };

} // MenuSystem

#endif //MEGABYTESTORE_MENUINFOITEM_H
