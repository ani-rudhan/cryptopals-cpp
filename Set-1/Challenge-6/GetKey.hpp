#pragma once

#include <vector>

#include "singleByteXORCipher.hpp"
#include "HexEncode.hpp"

inline std::string GetKey(const std::string &inputString, int keysize) {
    std::string key = "";
    if (keysize <= 0) {
        return key;
    }
    key.reserve(static_cast<std::size_t>(keysize));

    std::vector<std::string> singleBlkVec;

    for (int i = 0; i < keysize; i++) {
        std::string singleBlkStr = "";
        singleBlkVec.push_back(singleBlkStr);
    }

    for (int idx = 0; idx < static_cast<int>(inputString.size()); idx++) {
        singleBlkVec[idx % keysize] += inputString[idx];
    }

    for (const auto &itr : singleBlkVec) {
        auto result = GetSingleByteCipher(HexEncode(itr));
        key += static_cast<char>(result.first);
    }

    return key;
}