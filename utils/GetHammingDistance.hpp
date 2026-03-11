#pragma once

#include <cstdint>
#include <string>
#include <bitset>

inline int GetBitwiseHammingDistance(const std::string &firstStr, const std::string &secondStr) {
    if (firstStr.size() != secondStr.size()) { return -1; }
    
    int distance = 0;

    for (int idx = 0; idx < static_cast<int>(firstStr.size()); idx++) {
        std::bitset<8> setbitCount  = static_cast<unsigned char>(firstStr[idx]) ^ static_cast<unsigned char>(secondStr[idx]);
        distance += setbitCount.count();
    }

    return distance;
}

inline int GetBitwiseHammingDistance(uint8_t firstByte, uint8_t secondByte) {
    uint8_t byte = firstByte ^ secondByte;
    std::bitset<8> setbitCount(byte);
    return setbitCount.count();
}

inline int GetCharwiseHammingDistance(const std::string &firstStr, const std::string &secondStr) {
    if (firstStr.size() != secondStr.size()) { return -1; }
    
    int distance = 0;

    for (int idx = 0; idx < static_cast<int>(firstStr.size()); idx++) {
        if (firstStr[idx] != secondStr[idx]) {
            distance += 1;
        }
    }

    return distance;
}
