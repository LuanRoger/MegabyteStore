//
// Created by Vinicius on 27/10/2022.
//

#include "Motherboard.h"

namespace Models {
    Motherboard::Motherboard(Socket socket, string chipset, string memorySupport, string brand, string model, int id, int quantity, double value) :
    Hardware(brand, model, id, quantity, value, MOTHERBOARDTYPE), socket(socket) {
        setChipset(chipset);
        setMemorySupport(memorySupport);
    }


    string Motherboard::getChipset() {
        return chipset;
    }

    void Motherboard::setChipset(string newChipset) {
        chipset = newChipset;
    }

    string Motherboard::getMemorySupport() {
        return memorySupport;
    }

    void Motherboard::setMemorySupport(string newMemorySupport) {
        memorySupport = newMemorySupport;
    }

    void Motherboard::View(){
        cout << "ID: " << id << endl;
        cout << "Quantidade: " << quantity << endl;
        cout << "Valor: " << value << endl;
        cout << "Marca: " << brand << endl;
        cout << "Modelo: " << model << endl;
        cout << "Chipset: " << chipset << endl;
        cout << "Socket: " << socket.getSocketType() << endl;
        cout << "Suporte de Memoria: " << memorySupport << endl;
    }

    json Motherboard::ToJson() {
        json jsonMotherboard;
        jsonMotherboard = {
                { "id", id },
                {"type", productType },
                {"quantity", quantity},
                {"value", value},
                {"brand", brand},
                {"model", model},
                {"socket", socket.ToJson()},
                {"chipset", chipset},
                {"memory_support", memorySupport},
        };
        return jsonMotherboard;
    }

    Motherboard* Motherboard::FromJson(json jsonObject) {
        Motherboard* motherboard = new Motherboard(Socket::FromJson(jsonObject["socket"]),
                           jsonObject["chipset"],
                           jsonObject["memory_support"],
                           jsonObject["brand"],
                           jsonObject["model"],
                           jsonObject["id"],
                           jsonObject["quantity"],
                           jsonObject["value"]);

        return motherboard;
    }
}