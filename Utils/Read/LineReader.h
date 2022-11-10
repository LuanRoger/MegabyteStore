//
// Created by luanr on 10/11/2022.
//

#ifndef MEGABYTESTORE_LINEREADER_H
#define MEGABYTESTORE_LINEREADER_H

#include <iostream>
#include <string>
#include "ReaderOptions.h"

namespace Read {
    class LineReader {
    private:
        ReaderOptions readerOptions;
        static std::string exitCommand;

        /// Return if has problems.
        bool ValidateRead(std::string readedText);
        bool ValidateReadInt(std::string readedText);
    public:
        LineReader(ReaderOptions readerOptions);
        std::string ReadString(std::string text, bool loop = false);
        int ReadInt(std::string text, bool loop = false);
    };
}


#endif //MEGABYTESTORE_LINEREADER_H
