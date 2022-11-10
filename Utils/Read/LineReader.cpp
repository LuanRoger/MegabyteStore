//
// Created by luanr on 10/11/2022.
//

#include <algorithm>
#include "LineReader.h"

namespace Read {
    std::string LineReader::exitCommand = "/exit";

    LineReader::LineReader(ReaderOptions readerOptions) : readerOptions(readerOptions) {}

    std::string LineReader::ReadString(std::string text, bool loop) {
        bool running = loop;
        std::string output = NULL;

        do {
            std::cout << text << std::endl;
            if(loop)
                std::cout << "[ " << exitCommand << " ] - Sair." << std::endl;

            std::getline(std::cin, output);

            if(ValidateRead(output)) {
                std::cout << readerOptions.getInvalidOptionText() << std::endl;
                continue;
            }
            else if(output.compare(exitCommand) == 0)
                running = false;

            running = false;
        } while (running);

        return output;
    }
    int LineReader::ReadInt(std::string text, bool loop) {
        bool running = loop;
        int output = -1;
        std::string buffer = "";

        do {
            std::cout << text << std::endl;
            if(loop)
                std::cout << "[ " << exitCommand << " ] - Sair." << std::endl;

            std::getline(std::cin, buffer);

            if(ValidateReadInt(buffer)) {
                std::cout << readerOptions.getInvalidOptionText() << std::endl;
                buffer = "";
                continue;
            }
            else if(loop && buffer.compare(exitCommand) == 0)
                running = false;

            running = false;
        } while (running);

        if(!buffer.empty())
            output = std::stoi(buffer);
        return output;
    }

    bool LineReader::ValidateRead(std::string readedText) {
        return !readerOptions.isAllowEmpty() && readedText.empty();
    }

    bool LineReader::ValidateReadInt(std::string readedText) {
        bool isDigit = std::find_if(readedText.begin(),
                                    readedText.end(),
                                    [](unsigned char c) { return !std::isdigit(c); }) == readedText.end();
        return !readerOptions.isAllowEmpty() && readedText.empty() || !isDigit;
    }
}