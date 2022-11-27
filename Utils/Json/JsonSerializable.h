//
// Created by luanr on 21/11/2022.
//

#ifndef MEGABYTESTORE_JSONSERIALIZABLE_H
#define MEGABYTESTORE_JSONSERIALIZABLE_H

#include <string>
#include "json.hpp"

using namespace nlohmann;

namespace JsonUtils {
    class JsonSerializable {
        virtual json ToJson() = 0;
        //Is important to implement the static factory
        //in each [JsonSerializable] implementation.
        //Like this:
        //static T* FromJson(json jsonObject);
    };
}

#endif //MEGABYTESTORE_JSONSERIALIZABLE_H