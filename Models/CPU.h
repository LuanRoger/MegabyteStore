//
// Created by Vinicius on 27/10/2022.
//

#ifndef MEGABYTESTORE_CPU_H
#define MEGABYTESTORE_CPU_H
#include "Hardware.h"
#include "Socket.h"
#include "string"
#include "../Utils/Json/json.hpp"

using namespace nlohmann;

namespace Models {
    class CPU : public Hardware, public Socket {
    private:
        string socket;
        int cores;
        int threads;
        double basicClock;
        double boostMaximumClock;

    public:
        CPU(string socket, int cores, int threads, double basicClock, double boostMaximumClock, string brand, string model, int id, int quantity, double value);

        string getSocket();
        void setSocket(string newSocket);

        int getCores();
        void setCores(int newCores);

        int getThreads();
        void setThreads(int newThreads);

        double getBasicClock();
        void setBasicClock(double newBasicClock);

        double getBoostMaximumClock();
        void setBoostMaximumClock(double newBoostMaximumClock);

        void View() override;

        json ToJson() override;
        static CPU* FromJson(json jsonObject);
    };
}

#endif //MEGABYTESTORE_CPU_H
