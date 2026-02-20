#pragma once

#include <string>

std::string HexDecode(std::string hexEncString) {
    std::string result;
    for (int idx = 0; idx < hexEncString.size(); ) {
        result += static_cast<char>(std::stoul(hexEncString.substr(idx, 2), nullptr, 16));
        idx += 2;
    }

    return result;
}