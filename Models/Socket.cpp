//
// Created by Vinicius on 27/10/2022.
//

#include "Socket.h"

namespace Models {
    Socket::Socket(string type) {
        this->type = type;
    }

    std::string Socket::getSocketType() {
        return type;
    }

    json Socket::ToJson() {
        json jsonSocket;
        jsonSocket = {
                { "type", type }
        };

        return jsonSocket;
    }

    Socket Socket::FromJson(json jsonObject) {
        Socket socket(
                jsonObject["type"]
                );

        return socket;
    }
}