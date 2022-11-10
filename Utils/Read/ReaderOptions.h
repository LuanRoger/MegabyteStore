//
// Created by luanr on 10/11/2022.
//

#ifndef MEGABYTESTORE_READEROPTIONS_H
#define MEGABYTESTORE_READEROPTIONS_H

#include <string>

namespace Read {

    class ReaderOptions {
    private:
        std::string invalidOptionText;
        bool allowEmpty;

    public:
        ReaderOptions(std::string invalidOptionText, bool allowEmpty);

        std::string getInvalidOptionText() const;

        bool isAllowEmpty() const;
    };

} // ReadString

#endif //MEGABYTESTORE_READEROPTIONS_H
