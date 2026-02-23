#pragma once

#include <string>
#include <bitset>
#include <sstream>

#include "base64LUT.hpp"

std::string Base64Decode(std::string inputString) {
    std::string base64DecodedStr = "";
    std::string binaryStr = "";
    for (auto c : inputString) {
        binaryStr += std::bitset<6>(base64LookUpTable[static_cast<int>(c)]).to_string();
    }

    for (auto i = 0; i < binaryStr.length(); i += 8) {
        std::stringstream ss(binaryStr.substr(i, 8));
        std::bitset<8> bits;
        ss >> bits;
        base64DecodedStr += static_cast<char>(bits.to_ulong());
    }

    return base64DecodedStr;
}