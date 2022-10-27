//
// Created by Vinicius on 27/10/2022.
//

#ifndef MEGABYTESTORE_CPU_H
#define MEGABYTESTORE_CPU_H
#include "Hardware.h"
#include "Socket.h"
#include "string"

class CPU : Hardware,
        Socket{
private:
    string socket;
    int cores;
    int threads;
    double basicClock;
    double boostMaximumClock;

public:
    CPU(string socket, int cores, int threads, double basicClock, double boostMaximumClock, string marca, string modelo, double tdp, int id, int quantidade, double valor);

    string getSocket();

    int getCores();

    int getThreads();

    double getBasicClock();

    double getBoostMaximumClock();

    virtual void View();

};


#endif //MEGABYTESTORE_CPU_H
