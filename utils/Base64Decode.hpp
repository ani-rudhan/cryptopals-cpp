#pragma once

#include <string>
#include <vector>
#include <cctype>

#include "base64LUT.hpp"

inline std::string Base64Decode(const std::string &inputString) {
    std::vector<unsigned char> sextets;
    sextets.reserve(inputString.size());

    for (unsigned char c : inputString) {
        if (std::isspace(c)) {
            continue;
        }

        if (c == '=') {
            break;
        }

        signed char value = base64LookUpTable[static_cast<int>(c)];
        if (value >= 0) {
            sextets.push_back(static_cast<unsigned char>(value));
        }
    }

    std::string base64DecodedStr;
    base64DecodedStr.reserve((sextets.size() * 3) / 4 + 2);

    std::size_t idx = 0;
    while (idx + 3 < sextets.size()) {
        unsigned char a = sextets[idx];
        unsigned char b = sextets[idx + 1];
        unsigned char c = sextets[idx + 2];
        unsigned char d = sextets[idx + 3];

        base64DecodedStr.push_back(static_cast<char>((a << 2) | (b >> 4)));
        base64DecodedStr.push_back(static_cast<char>(((b & 0x0F) << 4) | (c >> 2)));
        base64DecodedStr.push_back(static_cast<char>(((c & 0x03) << 6) | d));
        idx += 4;
    }

    std::size_t remaining = sextets.size() - idx;
    if (remaining == 2) {
        unsigned char a = sextets[idx];
        unsigned char b = sextets[idx + 1];
        base64DecodedStr.push_back(static_cast<char>((a << 2) | (b >> 4)));
    } else if (remaining == 3) {
        unsigned char a = sextets[idx];
        unsigned char b = sextets[idx + 1];
        unsigned char c = sextets[idx + 2];
        base64DecodedStr.push_back(static_cast<char>((a << 2) | (b >> 4)));
        base64DecodedStr.push_back(static_cast<char>(((b & 0x0F) << 4) | (c >> 2)));
    }

    return base64DecodedStr;
}