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
        Motherboard(string socket, string chipset, string memorySupport, string marca, string modelo, int id, int quantidade, double valor);

        string getChipset();
        void setChipset(string novoChipset);

        string getMemorySupport();
        void setMemorySupport(string newMemorySupport);

        void View() override;
    };
}

#endif //MEGABYTESTORE_MOTHERBOARD_H
