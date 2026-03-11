#pragma once

#include <cctype>
#include <map>
#include <string>

inline std::map<char, int> GetCharCount_LowerCase(const std::string &inputString) {
    std::map<char, int> charCount;

    for (unsigned char c : inputString) {
        charCount[static_cast<char>(std::tolower(c))] += 1;
    }

    return charCount;
}