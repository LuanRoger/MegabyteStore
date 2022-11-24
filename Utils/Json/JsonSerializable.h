//
// Created by luanr on 21/11/2022.
//

#ifndef MEGABYTESTORE_JSONSERIALIZABLE_H
#define MEGABYTESTORE_JSONSERIALIZABLE_H

#include <string>

namespace JsonUtils {
    class JsonSerializable {
        virtual std::string ToJson() = 0;
        //Is important to implement the static factory
        //in each [JsonSerializable] implementation.
        //Like this:
        //static T* FromJson(std::string jsonText);
    };
}

#endif //MEGABYTESTORE_JSONSERIALIZABLE_H