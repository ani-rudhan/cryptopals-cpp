#pragma once

#include <map>
#include <string>

std::map<char, int> GetCharCount_LowerCase(std::string inputString) {
    std::map<char, int> charCount;

    for (auto c : inputString) {
        charCount[std::tolower(c)] += 1;
    }

    return charCount;
}