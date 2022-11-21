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
        std::string output = "?";

        do {
            std::cout << text << std::endl;

            std::getline(std::cin, output);

            if(ValidateRead(output)) {
                std::cout << readerOptions.getInvalidOptionText() << std::endl;
                output = "?";

                if(loop)
                    continue;
            }

            running = false;
        } while (running);

        return output;
    }
    int LineReader::ReadInt(std::string text, bool loop) {
        bool running = loop;
        int output = -1;
        std::string buffer;

        do {
            std::cout << text << std::endl;

            std::getline(std::cin, buffer);

            if(ValidateReadInt(buffer)) {
                std::cout << readerOptions.getInvalidOptionText() << std::endl;
                buffer = "";

                if(loop)
                    continue;
            }

            running = false;
        } while (running);

        if(!buffer.empty())
            output = std::stoi(buffer);
        return output;
    }
    double LineReader::ReadDouble(std::string text, bool loop) {
        bool running = loop;
        double output = -1.0;
        std::string buffer;

        do {
            std::cout << text << std::endl;

            std::getline(std::cin, buffer);

            if(ValidateReadDouble(buffer)) {
                std::cout << readerOptions.getInvalidOptionText() << std::endl;
                buffer = "";

                if(loop)
                    continue;
            }

            running = false;
        } while (running);

        if(!buffer.empty())
            output = std::stod(buffer);
        return output;
    }
    bool LineReader::ReadBool(std::string text, bool loop) {
        bool running = loop;
        bool output = false;
        std::string buffer;

        do {
            std::cout << text << std::endl;

            std::getline(std::cin, buffer);

            if(ValidadeReadBool(buffer)) {
                std::cout << readerOptions.getInvalidOptionText() << std::endl;
                buffer = "";

                if(loop)
                    continue;
            }

            running = false;
        } while (running);

        if(!buffer.empty())
            output = buffer[0] == 's';
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

    bool LineReader::ValidateReadDouble(std::string readedText) {
        bool isDoubleDigit = std::find_if(readedText.begin(),
                                          readedText.end(),
                                          [](unsigned char c) { return !std::isdigit(c) && c != '.'; }) == readedText.end();
        return !readerOptions.isAllowEmpty() && readedText.empty() || !isDoubleDigit;
    }

    bool LineReader::ValidadeReadBool(std::string readedText) {
        if(readedText.empty()) return true;

        return readedText[0] != 's' && readedText[0] != 'n';
    }
}