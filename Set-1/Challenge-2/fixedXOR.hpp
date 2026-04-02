#pragma once

#include <string>

#include "HexDecode.hpp"
#include "HexEncode.hpp"

inline std::string FixedLengthXOR(const std::string &stringA, const std::string &stringB)
{
    if (stringA.size() != stringB.size()) {
        throw std::invalid_argument("Inputs must be equal-length hex strings");
    }

    auto bytesA = HexDecodeToBytes(stringA);
    auto bytesB = HexDecodeToBytes(stringB);
    std::string xoredBytes;
    xoredBytes.reserve(bytesA.size());

    for (std::size_t i = 0; i < bytesA.size(); i++) {
        xoredBytes.push_back(static_cast<char>(bytesA[i] ^ bytesB[i]));
    }

    return HexEncode(xoredBytes);
}
