//
// Created by luanr on 29/10/2022.
//

#include "OpenSubmenuCommand.h"

namespace MenuSystem {
    OpenSubmenuCommand::OpenSubmenuCommand(Menu *submenu) {
        this->submenu = submenu;
    }

    void OpenSubmenuCommand::Execute() {
        submenu->Start();
    }
} // MenuSystem