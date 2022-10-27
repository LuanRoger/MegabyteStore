//
// Created by Vinicius on 27/10/2022.
//

#ifndef MEGABYTESTORE_PLACAMAE_H
#define MEGABYTESTORE_PLACAMAE_H
#include "Hardware.h"
#include "Socket.h"
#include "string"

using namespace std;

class PlacaMae : public Hardware, Socket{
private:
    string chipset;
    string memorySupport;

public:
    PlacaMae(string socket, string chipset, string memorySupport, string marca, string modelo, double tdp, int id, int quantidade, double valor);

    string getChipset();
    void setChipset(string novoChipset);

    string getMemorySupport();
    void setMemorySupport(string newMemorySupport);

    void View() override;
};


#endif //MEGABYTESTORE_PLACAMAE_H
