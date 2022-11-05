//
// Created by Vinicius on 27/10/2022.
//

#include "CPU.h"

CPU::CPU(string socket, int cores, int threads, double basicClock, double boostMaximumClock, string marca, string modelo, int id, int quantidade, double valor) : Hardware(marca, modelo, id, quantidade, valor),Socket(socket) {
    this->socket = socket;
    setCores(cores);
    setThreads(threads);
    setBasicClock(basicClock);
    setBoostMaximumClock(boostMaximumClock);
}

string CPU::getSocket() {
    return socket;
}

void CPU::setSocket(string newSocket) {
    socket = newSocket;
}

int CPU::getCores() {
    return cores;
}

void CPU::setCores(int newCores) {
    cores = newCores;
}

int CPU::getThreads() {
    return threads;
}

void CPU::setThreads(int newThreads) {
    threads = newThreads;
}

double CPU::getBasicClock() {
    return basicClock;
}

void CPU::setBasicClock(double newBasicClock) {
    basicClock = newBasicClock;
}

double CPU::getBoostMaximumClock() {
    return boostMaximumClock;
}

void CPU::setBoostMaximumClock(double newBoostMaximumClock) {
    boostMaximumClock = newBoostMaximumClock;
}


void CPU::View() {
    cout << "ID: " << id << endl;
    cout << "Quantidade: " << quantidade << endl;
    cout << "Valor: " << valor << endl;
    cout << "Marca: " << marca << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Socket: " << type << endl;
    cout << "Nucleos: " << cores << endl;
    cout << "Threads: " << threads << endl;
    cout << "Clock basico: " << basicClock << endl;
    cout << "Clock maximo com boost: " << boostMaximumClock << endl;

}


