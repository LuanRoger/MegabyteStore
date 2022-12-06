//
// Created by luanr on 26/10/2022.
//

#ifndef MEGABYTESTORE_MENU_H
#define MEGABYTESTORE_MENU_H

#include <functional>
#include "string"
#include "vector"
#include "string"
#include "iostream"
#include "MenuInfoItem.h"
#include "../../Utils/Read/LineReader.h"
#include "../../Utils/Read/ReaderOptions.h"

using namespace Read;

namespace MenuSystem {
    typedef std::function<bool()> MenuPredictor;

    class Menu {
    private:
        std::string header;
        std::string content;
        std::vector<MenuInfoItem> menuMapping;
        bool running;
        std::function<void()> onMenuStop;

        void RunMenu();
        void RunMenu(MenuPredictor menuPredictor);
        void PrintHeaderContent();
        void PrintOptions();
        void ClearResult();
    public:
        Menu(std::string header);
        Menu(std::string header, std::string content);

        void SetHeader(std::string header);
        void SetContent(std::string content);
        void SetOnMenuStop(std::function<void()> onMenuStop);
        void AddMenu(MenuInfoItem menuInfo);

        void Start(MenuPredictor menuPredictor);
        void Start();
        void Stop();
    };

} // MenuSystem

#endif //MEGABYTESTORE_MENU_H
