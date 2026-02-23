#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>

#include "singleByteXORCipher.hpp"
#include "HexEncode.hpp"

std::string GetKey(std::string inputString, int keysize) {
    std::string key = "";
    std::vector<std::string> singleBlkVec;

    for (int i = 0; i < keysize; i++) {
        std::string singleBlkStr = "";
        singleBlkVec.push_back(singleBlkStr);
    }

    for (int idx = 0; idx < inputString.size(); idx++) {
        singleBlkVec[idx % keysize] += inputString[idx];
    }

    for (auto itr : singleBlkVec) {
        // std::cout << itr << std::endl;
        // std::cout << "----------" << std::endl;

        auto result = GetSingleByteCipher(HexEncode(itr));

        std::cout << "cipher: " << result.first << " score: " << result.second << std::endl;
        // std::cout << "-------\n";
        key += static_cast<char>(result.first);
    }
    std::cout << key << std::endl;
    return key;
}