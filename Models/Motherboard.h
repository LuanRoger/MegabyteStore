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
    class Motherboard : public Hardware {
    private:
        Socket socket;
        string chipset;
        string memorySupport;

    public:
        Motherboard(Socket socket, string chipset, string memorySupport, string brand, string model, int id, int quantity, double value);

        string getChipset();
        void setChipset(string newChipset);

        string getMemorySupport();
        void setMemorySupport(string newMemorySupport);

        void View() override;

        json ToJson() override;
        static Motherboard* FromJson(json jsonObject);
    };
}

#endif //MEGABYTESTORE_MOTHERBOARD_H
