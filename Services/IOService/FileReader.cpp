//
// Created by luanr on 23/11/2022.
//

#include "FileReader.h"

namespace IOService {
    FileReader::FileReader(std::string filepath) {
        this->filepath = filepath;
    }

    std::string FileReader::ReadAll() {
        std::string buffer;
        std::ifstream readStream;

        readStream.open(filepath);
        while (readStream.eof()) {
            readStream >> buffer;
        }

        return buffer;
    }
} // IOService