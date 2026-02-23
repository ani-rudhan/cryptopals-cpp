#pragma once

#include <iostream>
#include <bitset>
#include <sstream>
#include <iomanip>

std::string EncryptUsingRepearingKeyXOR(std::string inputString, std::string key) {
    std::string resultString = "";
    
    int stridx, keyidx = 0;
    while (stridx < inputString.size()) {
        keyidx = (keyidx % key.size());
        auto encryptedChar = inputString[stridx] ^ key[keyidx];
        std::stringstream ss;
        ss << std::hex << std::setw(2) << std::setfill('0') << encryptedChar;
        resultString += ss.str();
        stridx += 1;
        keyidx += 1;
    }
    return resultString;
}