#pragma once

#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

inline uint8_t HexCharToInt(char c) {
    if (c >= '0' && c <= '9') return static_cast<uint8_t>(c - '0');
    if (c >= 'a' && c <= 'f') return static_cast<uint8_t>(c - 'a' + 10);
    if (c >= 'A' && c <= 'F') return static_cast<uint8_t>(c - 'A' + 10);
    throw std::invalid_argument("Invalid hex character");
    return 0;
}

inline std::vector<uint8_t> HexDecodeToBytes(const std::string &hex) {
    if (hex.length() % 2 != 0) {
        throw std::invalid_argument("Hex string must have an even length");
    }

    std::vector<uint8_t> bytes;
    bytes.reserve(hex.length() / 2);

    for (std::size_t i = 0; i < hex.length(); i += 2) {
        uint8_t high = HexCharToInt(hex[i]);
        uint8_t low  = HexCharToInt(hex[i + 1]);
        bytes.push_back(static_cast<uint8_t>((high << 4) | low));
    }

    return bytes;
}

inline std::string HexDecodeToString(const std::string &hexEncString) {
    std::string resultStr;
    auto bytes = HexDecodeToBytes(hexEncString);
    resultStr.reserve(bytes.size());

    for (uint8_t value : bytes) {
        resultStr.push_back(static_cast<char>(value));
    }

    return resultStr;
}