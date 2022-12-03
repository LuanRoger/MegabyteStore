//
// Created by Vinicius on 27/10/2022.
//

#ifndef MEGABYTESTORE_SOCKET_H
#define MEGABYTESTORE_SOCKET_H

#include <string>
#include "Hardware.h"
#include "../Utils/Json/JsonSerializable.h"
#include "../Utils/Json/json.hpp"

using namespace nlohmann;
using namespace JsonUtils;

namespace Models {
    class Socket : public JsonSerializable {
    private:
        std::string type;

    public:
        Socket(string type);

        std::string getSocketType();

        json ToJson() override;
        static Socket FromJson(json jsonObject);
    };
}

#endif //MEGABYTESTORE_SOCKET_H
