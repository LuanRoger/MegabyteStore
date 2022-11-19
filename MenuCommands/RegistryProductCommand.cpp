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
        string brand;
        string model;
        int quantity;
        double value;

        LineReader lineReader(ReaderOptions("Entre com uma opcao valida.", false));

        id = lineReader.ReadInt("Digite o ID");

        socket = lineReader.ReadString("Digite o socket");

        cores = lineReader.ReadInt("Digite a quantity de cores");

        threads = lineReader.ReadInt("Digite a quantity de threads");

        basicClock = lineReader.ReadDouble("Digite o clock base");

        boostMaximumClock = lineReader.ReadDouble("Digite o clock maximo");

        brand = lineReader.ReadString("Digite a brand");

        model = lineReader.ReadString("Digite o brand");

        quantity = lineReader.ReadInt("Digite o quantity");

        value = lineReader.ReadDouble("Digite o value");

        cout << "OPERACAO REALIZADA COM SUCESSO" << endl;

        return new Models::CPU(socket, cores, threads, basicClock,
                               boostMaximumClock, brand, model,
                               id, quantity, value);
    }

    Models::GPU *RegistryProductCommand::RegistryGPU() {
        int id;
        string chipset;
        int cudaCores;
        int VRAMCapacity;
        string VRAMType;
        int VRAMSpeed;
        string brand;
        string model;
        int quantity;
        double value;

        LineReader lineReader(ReaderOptions("Entre com uma opcao valida.", false));

        id = lineReader.ReadInt("Digite o ID");

        chipset = lineReader.ReadString("Digite o CHIPSET: ");

        cudaCores = lineReader.ReadInt("Digite a quantity de CORES: ");

        VRAMCapacity = lineReader.ReadInt("Digite a Capacidade de VRAM: ");

        VRAMType = lineReader.ReadString("Digite o Tipo de VRAM: ");

        VRAMSpeed = lineReader.ReadInt("Digite a velocidade de VRAM: ");

        brand = lineReader.ReadString("Digite a brand");

        model = lineReader.ReadString("Digite o model");

        quantity = lineReader.ReadInt("Digite o quantity");

        value = lineReader.ReadDouble("Digite o value");

        cout << "OPERACAO REALIZADA COM SUCESSO" << endl;

        return new Models::GPU(chipset, cudaCores, VRAMCapacity, VRAMType,
                               VRAMSpeed, brand, model,
                               id, quantity, value);
    }

    Models::Motherboard *RegistryProductCommand::RegistryMotherboard() {
        int id;
        string chipset;
        string memorySupport;
        string socket;
        string brand;
        string model;
        int quantity;
        double value;

        LineReader lineReader(ReaderOptions("Entre com uma opcao valida.", false));

        id = lineReader.ReadInt("Digite o ID");

        chipset = lineReader.ReadString("Digite o CHIPSET: ");

        socket = lineReader.ReadString("Digite o socket: ");

        memorySupport = lineReader.ReadString("Digite o tipo de memoria suportada: ");

        brand = lineReader.ReadString("Digite a brand");

        model = lineReader.ReadString("Digite o model");

        quantity = lineReader.ReadInt("Digite o quantity");

        value = lineReader.ReadDouble("Digite o value");

        cout << "OPERACAO REALIZADA COM SUCESSO" << endl;

        return new Models::Motherboard(socket, chipset, memorySupport, brand, model,
                                       id, quantity, value);
    }

    Models::PowerSupply *RegistryProductCommand::RegistryPowerSupply() {
        string outputCapacity;
        string inputVoltage;
        string PFC;
        string eightyPlusCertification;
        int id;
        string brand;
        string model;
        int quantity;
        double value;
        bool option1;
        bool option2;

        LineReader lineReader(ReaderOptions("Entre com uma opcao valida.", false));

        id = lineReader.ReadInt("Digite o ID");

        outputCapacity = lineReader.ReadString("Digite a Capacidade: ");

        inputVoltage = lineReader.ReadString("Digite a Voltagem: ");

        PFC = lineReader.ReadString("PFC ativo (S/N): ");

        eightyPlusCertification = lineReader.ReadString("Certificado 80 plus (S/N): ");

        brand = lineReader.ReadString("Digite a brand");

        model = lineReader.ReadString("Digite o model");

        quantity = lineReader.ReadInt("Digite o quantity");

        value = lineReader.ReadDouble("Digite o value");

        cout << "OPERACAO REALIZADA COM SUCESSO" << endl;


        option1 = (PFC == "N") ? false : true;
        option2 = (eightyPlusCertification == "N") ? false : true;

        return new Models::PowerSupply(outputCapacity, inputVoltage, option1, option2, brand,
                                       model, id, quantity, value);
    }

    Models::RAMMemory *RegistryProductCommand::RegistryRAMMemory() {
        string memoryType;
        int frequency;
        int capacity;
        int id;
        string brand;
        string model;
        int quantity;
        double value;

        LineReader lineReader(ReaderOptions("Entre com uma opcao valida.", false));

        id = lineReader.ReadInt("Digite o ID");

        memoryType = lineReader.ReadString("Digite o tipo da memoria: ");

        frequency = lineReader.ReadInt("Digite a frequencia da memeoria: ");

        capacity = lineReader.ReadInt("Digite a capacidade da memoria");

        brand = lineReader.ReadString("Digite a brand");

        model = lineReader.ReadString("Digite o model");

        quantity = lineReader.ReadInt("Digite o quantity");

        value = lineReader.ReadDouble("Digite o value");

        cout << "OPERACAO REALIZADA COM SUCESSO" << endl;

        return new Models::RAMMemory(memoryType, frequency, capacity, brand,
                                     model, id, quantity, value);
    }

    Models::StorageUnit *RegistryProductCommand::RegistryStorageUnit() {
        StorageType type;
        int writeSpeed;
        int readSpeed;
        int id;
        string brand;
        string model;
        int quantity;
        double value;

        LineReader lineReader(ReaderOptions("Entre com uma opcao valida.", false));

        id = lineReader.ReadInt("Digite o ID");

        type = static_cast<StorageType>(lineReader.ReadInt("Digite o tipo do armazenamento: "));

        writeSpeed = lineReader.ReadInt("Digite a velocidade de escrita: ");

        readSpeed = lineReader.ReadInt("Digite a velocidade de leitura: ");

        brand = lineReader.ReadString("Digite a brand");

        model = lineReader.ReadString("Digite o model");

        quantity = lineReader.ReadInt("Digite o quantity");

        value = lineReader.ReadDouble("Digite o value");

        cout << "OPERACAO REALIZADA COM SUCESSO" << endl;

        return new Models::StorageUnit(type, writeSpeed, readSpeed, brand,
                                       model, id, quantity, value);
    }


    void RegistryProductCommand::Execute() {
        LineReader lineReader(ReaderOptions("Entre com uma opcao valida.", false));
        Models::Product* newProduct = nullptr;

        cout << "[ 1 ] - CPU" << endl;
        cout << "[ 2 ] - GPU" << endl;
        cout << "[ 3 ] - Placa Mae" << endl;
        cout << "[ 4 ] - Fonte" << endl;
        cout << "[ 5 ] - Memoria RAM" << endl;
        cout << "[ 6 ] - Unidade de armazenamento" << endl;
        cout << "[ 0 ] - Voltar" << endl;
        int choice;

        choice = lineReader.ReadInt("Digite qual tipo de produto deseja cadastrar:");

        switch (choice) {
            case 1:
                newProduct = RegistryCPU();
                break;
            case 2:
                newProduct = RegistryGPU();
                break;
            case 3:
                newProduct = RegistryMotherboard();
                break;
            case 4:
                newProduct = RegistryPowerSupply();
                break;
            case 5:
                newProduct = RegistryRAMMemory();
                break;
            case 6:
                newProduct = RegistryStorageUnit();
                break;
        }

        if(choice != 0)
            productStorage->AddProduct(newProduct);
    }
}