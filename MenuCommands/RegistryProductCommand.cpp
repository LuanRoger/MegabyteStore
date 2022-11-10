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

        LineReader lineReader(ReaderOptions("Entre com uma opcao valida.", false));

        id = lineReader.ReadInt("Digite o ID");

        socket = lineReader.ReadString("Digite o socket");

        cores = lineReader.ReadInt("Digite a quantidade de cores");

        threads = lineReader.ReadInt("Digite a quantidade de threads");

        cout << "Digite o clock base" << endl;
        cin >> basicClock;

        cout << "Digite o clock maximo" << endl;
        cin >> boostMaximumClock;

        marca = lineReader.ReadString("Digite a marca");

        modelo = lineReader.ReadString("Digite o modelo");

        quantidade = lineReader.ReadInt("Digite o quantidade");

        cout << "Digite o valor" << endl;
        cin >> valor;

        return new Models::CPU(socket, cores, threads, basicClock,
                       boostMaximumClock, marca, modelo,
                       id, quantidade, valor);
    }

    void RegistryProductCommand::Execute() {
        LineReader lineReader(ReaderOptions("Entre com uma opcao valida.", false));
        Models::Product* newProduct = nullptr;

        cout << "[ 1 ] - CPU" << endl;
        cout << "[ 0 ] - Voltar" << endl;
        int choice;

        choice = lineReader.ReadInt("Digite qual tipo de produto deseja cadastrar:");

        switch (choice) {
            case 1:
                newProduct = RegistryCPU();
                break;
        }

        if(choice != 0)
            productStorage->AddProduct(newProduct);
    }
}