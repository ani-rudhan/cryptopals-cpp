#pragma once

#include <string>

#include "base64Char.hpp"

inline std::string Base64Encode(const std::string &inputString) {
    std::string base64EncodedStr;
    base64EncodedStr.reserve(((inputString.size() + 2) / 3) * 4);

    std::size_t i = 0;
    while (i + 2 < inputString.size()) {
        unsigned char a = static_cast<unsigned char>(inputString[i]);
        unsigned char b = static_cast<unsigned char>(inputString[i + 1]);
        unsigned char c = static_cast<unsigned char>(inputString[i + 2]);

        base64EncodedStr.push_back(base64Chars[(a >> 2) & 0x3F]);
        base64EncodedStr.push_back(base64Chars[((a & 0x03) << 4) | ((b >> 4) & 0x0F)]);
        base64EncodedStr.push_back(base64Chars[((b & 0x0F) << 2) | ((c >> 6) & 0x03)]);
        base64EncodedStr.push_back(base64Chars[c & 0x3F]);
        i += 3;
    }

    std::size_t remaining = inputString.size() - i;
    if (remaining == 1) {
        unsigned char a = static_cast<unsigned char>(inputString[i]);
        base64EncodedStr.push_back(base64Chars[(a >> 2) & 0x3F]);
        base64EncodedStr.push_back(base64Chars[(a & 0x03) << 4]);
        base64EncodedStr.push_back('=');
        base64EncodedStr.push_back('=');
    } else if (remaining == 2) {
        unsigned char a = static_cast<unsigned char>(inputString[i]);
        unsigned char b = static_cast<unsigned char>(inputString[i + 1]);
        base64EncodedStr.push_back(base64Chars[(a >> 2) & 0x3F]);
        base64EncodedStr.push_back(base64Chars[((a & 0x03) << 4) | ((b >> 4) & 0x0F)]);
        base64EncodedStr.push_back(base64Chars[(b & 0x0F) << 2]);
        base64EncodedStr.push_back('=');
    }

    return base64EncodedStr;
}