//
// Created by luanr on 29/10/2022.
//

#ifndef MEGABYTESTORE_OPENSUBMENUCOMMAND_H
#define MEGABYTESTORE_OPENSUBMENUCOMMAND_H

#include "../Menu.h"

namespace MenuSystem {

    class OpenSubmenuCommand : public IMenuCommand {
    private:
        Menu* submenu;

    public:
        OpenSubmenuCommand(Menu* submenu);

        void Execute() override;
    };

} // MenuSystem

#endif //MEGABYTESTORE_OPENSUBMENUCOMMAND_H
