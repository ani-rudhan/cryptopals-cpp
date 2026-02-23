#pragma once

#include <string>
#include <bitset>

int GetBitwiseHammingDistance(std::string firstStr, std::string secondStr) {
    if (firstStr.size() != secondStr.size()) { return -1; }
    
    int distance = 0;

    for (int idx = 0; idx < firstStr.size(); idx++) {
        std::bitset<8> setbitCount  = firstStr[idx] ^ secondStr[idx];
        distance += setbitCount.count();
    }

    return distance;
}

int GetCharwiseHammingDistance(std::string firstStr, std::string secondStr) {
    if (firstStr.size() != secondStr.size()) { return -1; }
    
    int distance = 0;

    for (int idx = 0; idx < firstStr.size(); idx++) {
        if (firstStr[idx] != secondStr[idx]) {
            distance += 1;
        }
    }

    return distance;
}
