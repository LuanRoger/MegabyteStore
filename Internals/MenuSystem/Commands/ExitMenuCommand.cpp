//
// Created by luanr on 28/10/2022.
//

#include "ExitMenuCommand.h"

namespace MenuSystem {
    ExitMenuCommand::ExitMenuCommand(MenuSystem::Menu *scopedMenu) {
        this->scopedMenu = scopedMenu;
    }
    void ExitMenuCommand::Execute() {
        scopedMenu->Stop();
    }
} // MenuSystem