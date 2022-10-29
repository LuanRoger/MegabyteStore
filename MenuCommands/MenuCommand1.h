//
// Created by luanr on 26/10/2022.
//

#ifndef MEGABYTESTORE_MENUCOMMAND1_H
#define MEGABYTESTORE_MENUCOMMAND1_H

#include "../Internals/MenuSystem/Commands/IMenuCommand.h"

namespace MenuCommand {
    class MenuCommand1 : public MenuSystem::IMenuCommand {
        virtual void Execute();
    };
}


#endif //MEGABYTESTORE_MENUCOMMAND1_H
