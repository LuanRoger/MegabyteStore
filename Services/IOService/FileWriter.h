//
// Created by luanr on 23/11/2022.
//

#ifndef MEGABYTESTORE_FILEWRITER_H
#define MEGABYTESTORE_FILEWRITER_H

#include <string>
#include <iostream>
#include <fstream>

namespace IOService {

    class FileWriter {
    private:
        std::string filepath;
        std::ofstream fileHandler;
        bool open;

    public:
        FileWriter(std::string filepath);

        void Start();
        void Write(std::string text);
        void Flush();
    };

} // IOService

#endif //MEGABYTESTORE_FILEWRITER_H
