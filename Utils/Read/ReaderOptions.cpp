//
// Created by luanr on 10/11/2022.
//

#include "ReaderOptions.h"

namespace Read {
    ReaderOptions::ReaderOptions(std::string invalidOptionText, bool allowEmpty){
        this->invalidOptionText = invalidOptionText;
        this->allowEmpty = allowEmpty;
    }

    std::string ReaderOptions::getInvalidOptionText() const {
        return invalidOptionText;
    }

    bool ReaderOptions::isAllowEmpty() const {
        return allowEmpty;
    }
} // ReadString