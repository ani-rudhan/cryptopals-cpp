#pragma once

#include <sstream>
#include <iomanip>

inline std::string EncryptUsingRepeatingKeyXOR(const std::string &inputString, const std::string &key) {
    std::string resultString = "";
    if (key.empty()) {
        return resultString;
    }
    resultString.reserve(inputString.size() * 2);
    
    std::size_t stridx = 0;
    std::size_t keyidx = 0;
    while (stridx < inputString.size()) {
        keyidx = (keyidx % key.size());
        auto encryptedChar = inputString[stridx] ^ key[keyidx];
        std::stringstream ss;
        ss << std::hex << std::setw(2) << std::setfill('0')
           << static_cast<int>(static_cast<unsigned char>(encryptedChar));
        resultString += ss.str();
        stridx += 1;
        keyidx += 1;
    }
    return resultString;
}