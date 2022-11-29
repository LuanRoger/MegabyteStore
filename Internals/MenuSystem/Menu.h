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

using namespace std;
using namespace Read;

namespace MenuSystem {
    typedef function<bool()> MenuPredictor;

    class Menu {
    private:
        string header;
        string content;
        vector<MenuInfoItem> menuMapping;
        bool running;
        function<void()> onMenuStop;

        void RunMenu();
        void RunMenu(MenuPredictor menuPredictor);
        void PrintHeaderContent();
        void PrintOptions();

    public:
        Menu(string header);
        Menu(string header, string content);

        void SetHeader(string header);
        void SetContent(string content);
        void SetOnMenuStop(function<void()> onMenuStop);
        void AddMenu(MenuInfoItem menuInfo);

        void Start(MenuPredictor menuPredictor);
        void Start();
        void Stop();
    };

} // MenuSystem

#endif //MEGABYTESTORE_MENU_H
