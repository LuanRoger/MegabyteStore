//
// Created by Vinicius on 28/10/2022.
//

#ifndef MEGABYTESTORE_RAMMEMORY_H
#define MEGABYTESTORE_RAMMEMORY_H
#include "Hardware.h"
#include "string"

using namespace std;
namespace Models {
    class RAMMemory : public Hardware{
    private:
        string memoryType;
        int frequency;
        int capacity;
    public:
        RAMMemory(string memoryType, int frequency, int capacity, string brand, string model, int id, int quantity, double value);

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
