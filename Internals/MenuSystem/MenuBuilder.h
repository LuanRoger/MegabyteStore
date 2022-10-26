#ifndef MEGABYTESTORE_MENUBUILDER_H
#define MEGABYTESTORE_MENUBUILDER_H

#include "map"
#include "string"
#include "MenuInfoItem.h"
#include "Menu.h"

namespace MenuSystem {
    typedef std::map<int, MenuInfoItem *> MenuMapping;

    class MenuBuilder {
    private:
        std::string* header;
        MenuMapping* menuMapping;

    public:
        MenuBuilder();

        void SetHeader(std::string* header);
        void AddMenu(int optionIndex, MenuInfoItem* menuInfo);
        MenuSystem::Menu* Build();
    };
}


#endif //MEGABYTESTORE_MENUBUILDER_H
