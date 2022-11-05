//
// Created by luanr on 26/10/2022.
//

#include "RegistryProductCommand.h"
#include "iostream"

namespace MenuCommand {
    RegistryProductCommand::RegistryProductCommand(MemoryStorage::ProductsStorage *productsStorage) {
        this->productStorage = productsStorage;
    }

    Models::CPU *RegistryProductCommand::RegistryCPU() {
        int id;
        string socket;
        int cores;
        int threads;
        double basicClock;
        double boostMaximumClock;
        string marca;
        string modelo;
        int quantidade;
        double valor;

        cout << "Digite o ID" << endl;
        cin >> id;

        cout << "Digite o socket" << endl;
        cin >> socket;

        cout << "Digite a quantidade de cores" << endl;
        cin >> cores;

        cout << "Digite a quantidade de threads" << endl;
        cin >> threads;

        cout << "Digite o clock base" << endl;
        cin >> basicClock;

        cout << "Digite o clock maximo" << endl;
        cin >> boostMaximumClock;

        cout << "Digite a marca" << endl;
        cin >> marca;

        cout << "Digite o modelo" << endl;
        cin >> modelo;

        cout << "Digite o quantidade" << endl;
        cin >> quantidade;

        cout << "Digite o valor" << endl;
        cin >> valor;

        return new Models::CPU(socket, cores, threads, basicClock,
                       boostMaximumClock, marca, modelo,
                       id, quantidade, valor);
    }

    void RegistryProductCommand::Execute() {
        Models::Product* newProduct = nullptr;

        cout << "Digite qual tipo de produto deseja cadastrar:" << endl;
        cout << "[ 1 ] - CPU" << endl;
        cout << "[ 0 ] - Voltar" << endl;
        int choice;

        cin >> choice;

        switch (choice) {
            case 1:
                newProduct = RegistryCPU();
                break;
        }

        if(choice != 0)
            productStorage->AddProduct(newProduct);
    }
}