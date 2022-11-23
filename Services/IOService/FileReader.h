//
// Created by luanr on 23/11/2022.
//

#ifndef MEGABYTESTORE_FILEREADER_H
#define MEGABYTESTORE_FILEREADER_H

#include <iostream>
#include <fstream>
#include <string>

namespace IOService {

    class FileReader {
    private:
        std::string filepath;

    public:
        FileReader(std::string filepath);

        std::string ReadAll();
    };

} // IOService

#endif //MEGABYTESTORE_FILEREADER_H
