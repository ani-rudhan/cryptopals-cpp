#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>

std::string DecryptUsingRepeatedKeyXOR(std::string strEncryptedUsingRepeatedKeyXOR, std::string key) {
    std::string decryptedStr = "";
    int stridx, keyidx = 0;
    while (stridx < strEncryptedUsingRepeatedKeyXOR.size()) {
        keyidx = (keyidx % key.size());
        decryptedStr += strEncryptedUsingRepeatedKeyXOR[stridx] ^ key[keyidx];
        
        stridx += 1;
        keyidx += 1;
    }
    return decryptedStr;
}