//
// Created by luanr on 23/11/2022.
//

#include "FileWriter.h"

namespace IOService {
    FileWriter::FileWriter(std::string filepath) {
        this->filepath = filepath;
        open = false;
    }

    void FileWriter::Start() {
        open = true;
        fileHandler.open(filepath);
    }

    void FileWriter::Write(std::string text) {
        if(!open) return;

        fileHandler << text;
    }
    void FileWriter::WriteLine(std::string text) {
        if(!open) return;

        fileHandler << text + '\n';
    }

    void FileWriter::Flush() {
        fileHandler.close();
        open = false;
    }


} // IOService