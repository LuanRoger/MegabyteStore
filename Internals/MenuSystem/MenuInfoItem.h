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
        bool escapeOption;
    public:
        MenuInfoItem(int optionNumber, std::string text, std::function<void()> action, bool escapeOption = false);

        int getOptionNumber() const;
        std::string getText();
        std::function<void()> getAction();
        void setAction(std::function<void()> action);
        bool isEscapeOption() const;
    };

} // MenuSystem

#endif //MEGABYTESTORE_MENUINFOITEM_H
