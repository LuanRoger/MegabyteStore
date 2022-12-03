//
// Created by luanr on 26/10/2022.
//

#include "RegisterProductCommand.h"

namespace MenuCommand {
    Models::CPU *RegisterProductCommand::RegistryCPU() {
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

        id = lineReader.ReadInt("Digite o ID:");

        socket = lineReader.ReadString("Digite o socket:");

        cores = lineReader.ReadInt("Digite a quantitade de cores:");

        threads = lineReader.ReadInt("Digite a quantitdade de threads:");

        basicClock = lineReader.ReadDouble("Digite o clock base:");

        boostMaximumClock = lineReader.ReadDouble("Digite o clock maximo:");

        brand = lineReader.ReadString("Digite a marca:");

        model = lineReader.ReadString("Digite o modelo:");

        quantity = lineReader.ReadInt("Digite a quantitade em estoque:");

        value = lineReader.ReadDouble("Digite o valor a ser vendido:");

        cout << "OPERACAO REALIZADA COM SUCESSO" << endl;

        return new Models::CPU(socket, cores, threads, basicClock,
                               boostMaximumClock, brand, model,
                               id, quantity, value);
    }

    Models::GPU *RegisterProductCommand::RegistryGPU() {
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

    Models::Motherboard *RegisterProductCommand::RegistryMotherboard() {
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

    Models::PowerSupply *RegisterProductCommand::RegistryPowerSupply() {
        string outputCapacity;
        string inputVoltage;
        bool PFC;
        bool eightyPlusCertification;
        int id;
        string brand;
        string model;
        int quantity;
        double value;
        bool option1;
        bool option2;

        LineReader lineReader(ReaderOptions("Entre com uma opcao valida.", false));

        id = lineReader.ReadInt("Digite o ID", true);

        outputCapacity = lineReader.ReadString("Digite a Capacidade: ");

        inputVoltage = lineReader.ReadString("Digite a Voltagem: ");

        PFC = lineReader.ReadBool("PFC ativo (s/n): ", true);

        eightyPlusCertification = lineReader.ReadBool("Certificado 80 plus (s/n): ", true);

        brand = lineReader.ReadString("Digite a brand");

        model = lineReader.ReadString("Digite o model");

        quantity = lineReader.ReadInt("Digite o quantity");

        value = lineReader.ReadDouble("Digite o value");

        cout << "OPERACAO REALIZADA COM SUCESSO" << endl;

        return new Models::PowerSupply(outputCapacity, inputVoltage, PFC, eightyPlusCertification, brand,
                                       model, id, quantity, value);
    }

    Models::RAMMemory *RegisterProductCommand::RegistryRAMMemory() {
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

    Models::StorageUnit *RegisterProductCommand::RegistryStorageUnit() {
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


    Product* RegisterProductCommand::Execute() {
        Product* newProduct = nullptr;

        Menu* registerProductMenu = new Menu("==Cadastrar produto==");
        registerProductMenu->AddMenu(MenuInfoItem(1, "CPU", [&newProduct]() {
            newProduct = RegistryCPU();
        }));
        registerProductMenu->AddMenu(MenuInfoItem(2, "GPU", [&newProduct]() {
            newProduct = RegistryGPU();
        }));
        registerProductMenu->AddMenu(MenuInfoItem(3, "Placa Mãe", [&newProduct]() {
            newProduct = RegistryMotherboard();
        }));
        registerProductMenu->AddMenu(MenuInfoItem(4, "Fonte", [&newProduct]() {
            newProduct = RegistryPowerSupply();
        }));
        registerProductMenu->AddMenu(MenuInfoItem(5, "Memoria RAM", [&newProduct]() {
            newProduct = RegistryRAMMemory();
        }));
        registerProductMenu->AddMenu(MenuInfoItem(6, "Unidade de armazenamento", [&newProduct]() {
            newProduct = RegistryStorageUnit();
        }));
        registerProductMenu->AddMenu(MenuInfoItem(0, "Voltar", [registerProductMenu]() {
            registerProductMenu->Stop();
        }));

        registerProductMenu->Start([&newProduct]() {
            return newProduct == nullptr;
        });

        return newProduct;
    }
}