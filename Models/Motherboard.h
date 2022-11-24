//
// Created by Vinicius on 27/10/2022.
//

#ifndef MEGABYTESTORE_MOTHERBOARD_H
#define MEGABYTESTORE_MOTHERBOARD_H
#include "Hardware.h"
#include "Socket.h"
#include "string"

using namespace std;

namespace Models {
    class Motherboard : public Hardware, Socket{
    private:
        string chipset;
        string memorySupport;

    public:
        Motherboard(string socket, string chipset, string memorySupport, string brand, string model, int id, int quantity, double value);

        string getChipset();
        void setChipset(string newChipset);

        string getMemorySupport();
        void setMemorySupport(string newMemorySupport);

        void View() override;

        std::string ToJson() override;
        static Motherboard* FromJson(std::string jsonText);
    };
}

#endif //MEGABYTESTORE_MOTHERBOARD_H
