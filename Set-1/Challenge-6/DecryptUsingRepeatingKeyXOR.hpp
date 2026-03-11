#pragma once

inline std::string DecryptUsingRepeatingKeyXOR(const std::string &encrypted, const std::string &key) {
    std::string decryptedStr = "";
    if (key.empty()) {
        return decryptedStr;
    }

    decryptedStr.reserve(encrypted.size());
    std::size_t stridx = 0;
    std::size_t keyidx = 0;
    while (stridx < encrypted.size()) {
        keyidx = (keyidx % key.size());
        decryptedStr += encrypted[stridx] ^ key[keyidx];
        
        stridx += 1;
        keyidx += 1;
    }
    return decryptedStr;
}