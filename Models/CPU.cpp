//
// Created by Vinicius on 27/10/2022.
//

#include "CPU.h"

CPU::CPU(string socket, int cores, int threads, double basicClock, double boostMaximumClock, string marca, string modelo, double tdp, int id, int quantidade, double valor) : Hardware(marca, modelo, tdp, id, quantidade, valor),Socket(socket) {
    this->cores = cores;
    this->threads = threads;
    this->basicClock = basicClock;
    this->boostMaximumClock = boostMaximumClock;
}

void CPU::View() {
    cout << "ID: " << id << endl;
    cout << "Quantidade: " << quantidade << endl;
    cout << "Valor: " << valor << endl;
    cout << "Marca: " << marca << endl;
    cout << "Modelo: " << modelo << endl;
    cout << "Tdp: " << tdp << endl;
    cout << "Socket: " << type << endl;
    cout << "Nucleos: " << cores << endl;
    cout << "Threads: " << threads << endl;
    cout << "Clock basico: " << basicClock << endl;
    cout << "Clock maximo com boost: " << boostMaximumClock << endl;

}


