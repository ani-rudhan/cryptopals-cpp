#pragma once

#include <string>
#include <bitset>
#include <sstream>

#include "base64Char.hpp"

std::string Base64Encode(std::string inputString) {
    std::string base64EncodedStr = "";
    std::string binaryStr = "";
    
    for (auto itr = inputString.begin(); itr != inputString.end(); itr++)
    {
        binaryStr += std::bitset<8>(static_cast<int>(*itr)).to_string();
    }

    for (auto i = 0; i < binaryStr.length(); i += 6)
    {
        std::stringstream sixBitBinStr(binaryStr.substr(i, 6));
        std::bitset<6> bits;
        sixBitBinStr >> bits;
        base64EncodedStr += base64Chars[bits.to_ulong()];
    }

    int paddingCnt = 0;
    if ((base64EncodedStr.length() % 4) == 0)
    {
        auto paddingCnt = 4 - (base64EncodedStr.length() % 4);
    }

    for (auto i = 0; i < paddingCnt; i++)
    {
        base64EncodedStr += "=";
    }

    return base64EncodedStr;
}