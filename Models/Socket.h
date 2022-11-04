//
// Created by Vinicius on 27/10/2022.
//

#ifndef MEGABYTESTORE_SOCKET_H
#define MEGABYTESTORE_SOCKET_H
#include "Hardware.h"
#include "string"

using namespace std;

class Socket{
protected:
    string type;

public:
    Socket(string type);
    string getType();
    void setType(string newType);
};


#endif //MEGABYTESTORE_SOCKET_H
