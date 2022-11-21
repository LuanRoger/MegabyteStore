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
        char positiveAweser = 's';
        char negativeAweser = 'n';

    public:
        ReaderOptions(std::string invalidOptionText, bool allowEmpty);
        ReaderOptions(std::string invalidOptionText, bool allowEmpty, char positiveAweser, char negativeAweser);

        std::string getInvalidOptionText() const;

        bool isAllowEmpty() const;
    };

} // ReadString

#endif //MEGABYTESTORE_READEROPTIONS_H
