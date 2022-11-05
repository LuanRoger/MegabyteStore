//
// Created by Vinicius on 28/10/2022.
//

#ifndef MEGABYTESTORE_RAMMEMORY_H
#define MEGABYTESTORE_RAMMEMORY_H
#include "Hardware.h"
#include "string"

using namespace std;
namespace Models {
    class RAMMemory : Hardware{
    private:
        string memoryType;
        int frequency;
        int capacity;
    public:
        RAMMemory(string memoryType, int frequency, int capacity, string marca, string modelo, int id, int quantidade, double valor);

        string getMemoryType();
        void setType(string newMemoryType);

        int getFrequency();
        void setFrequency(int newFrequency);

        int getCapacity();
        void setCapacity(int newCapacity);

        void View() override;
    };
}

#endif //MEGABYTESTORE_RAMMEMORY_H
