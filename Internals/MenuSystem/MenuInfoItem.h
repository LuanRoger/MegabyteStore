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
        bool persistResult = true;
    public:
        MenuInfoItem(int optionNumber, std::string text, std::function<void()> action, bool persistResult = true);

        int getOptionNumber() const;
        std::string getText();
        std::function<void()> getAction();
        bool getPersistResult() const;
    };

} // MenuSystem

#endif //MEGABYTESTORE_MENUINFOITEM_H
