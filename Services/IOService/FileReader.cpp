//
// Created by luanr on 23/11/2022.
//

#include <sstream>
#include "FileReader.h"

namespace IOService {
    FileReader::FileReader(std::string filepath) {
        this->filepath = filepath;
    }

    std::string FileReader::ReadAll() {
        std::stringstream fileText;
        std::ifstream readStream;

        readStream.open(filepath, std::ios::in);
        std::string fileLineBuffer;
        while (std::getline(readStream, fileLineBuffer))
            fileText << fileLineBuffer;

        return fileText.str();
    }

    bool FileReader::Exists() {
        std::ifstream existStream;
        existStream.open(filepath, std::fstream::in);
        bool exist = !(!existStream);
        existStream.close();

        return exist;
    }
} // IOService