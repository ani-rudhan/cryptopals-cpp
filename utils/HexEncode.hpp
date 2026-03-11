#pragma once

#include <sstream>
#include <iomanip>

inline std::string HexEncode(const std::string &inputStr) {
    std::string hexEncodedStr = "";
    for (unsigned char c : inputStr) {
        std::stringstream ss;
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);
        hexEncodedStr += ss.str();
    }
    return hexEncodedStr;
}