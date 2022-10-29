//
// Created by luanr on 28/10/2022.
//

#ifndef MEGABYTESTORE_EXITMENUCOMMAND_H
#define MEGABYTESTORE_EXITMENUCOMMAND_H

#include "IMenuCommand.h"
#include "Menu.h"

namespace MenuSystem {

    class ExitMenuCommand : public IMenuCommand {
    private:
        Menu* scopedMenu;

    public:
        ExitMenuCommand(Menu* scopedMenu);

        void Execute() override;
    };

} // MenuSystem

#endif //MEGABYTESTORE_EXITMENUCOMMAND_H
