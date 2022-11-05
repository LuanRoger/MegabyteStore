//
// Created by Vinicius on 27/10/2022.
//

#include "Socket.h"

namespace Models {
    Socket::Socket(string type) {
        setType(type);
    }

    string Socket::getType() {
        return type;
    }

    void Socket::setType(string newType) {
        type = newType;
    }
}