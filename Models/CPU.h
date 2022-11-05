//
// Created by Vinicius on 27/10/2022.
//

#ifndef MEGABYTESTORE_CPU_H
#define MEGABYTESTORE_CPU_H
#include "Hardware.h"
#include "Socket.h"
#include "string"

namespace Models {
    class CPU : public Hardware, public Socket{
    private:
        string socket;
        int cores;
        int threads;
        double basicClock;
        double boostMaximumClock;

    public:
        CPU(string socket, int cores, int threads, double basicClock, double boostMaximumClock, string marca, string modelo, int id, int quantidade, double valor);

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

    };
}

#endif //MEGABYTESTORE_CPU_H
