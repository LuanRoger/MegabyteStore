//
// Created by luanr on 26/10/2022.
//

#ifndef MEGABYTESTORE_IMENUCOMMAND_H
#define MEGABYTESTORE_IMENUCOMMAND_H

namespace MenuSystem {

    class IMenuCommand {
    public:
        virtual void Execute() = 0;
    };

} // MenuSystem

#endif //MEGABYTESTORE_IMENUCOMMAND_H
