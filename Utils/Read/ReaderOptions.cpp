//
// Created by luanr on 10/11/2022.
//

#include "ReaderOptions.h"

namespace Read {
    ReaderOptions::ReaderOptions(std::string invalidOptionText, bool allowEmpty){
        this->invalidOptionText = invalidOptionText;
        this->allowEmpty = allowEmpty;
    }
    ReaderOptions::ReaderOptions(std::string invalidOptionText, bool allowEmpty, char positiveAweser, char negativeAweser) {
        this->invalidOptionText = invalidOptionText;
        this->allowEmpty = allowEmpty;
        this->positiveAweser = positiveAweser;
        this->negativeAweser = negativeAweser;
    }

    std::string ReaderOptions::getInvalidOptionText() const {
        return invalidOptionText;
    }

    bool ReaderOptions::isAllowEmpty() const {
        return allowEmpty;
    }
} // ReadString