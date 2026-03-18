#pragma once

#include <map>
#include <iostream>
#include <string>
#include <fstream>

inline std::map<char, float> GetExpectedFreqDistMap_LowerCase(std::string filepathname = "") {
    if (filepathname.empty()) {
        filepathname = FREQ_DIST_PATH;
    }

    std::ifstream inFile(filepathname);
    std::map<char, float> result;

    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return result;
    }

    const std::string delimiter = "-D-";
    std::string line;
    while (std::getline(inFile, line)) {
        if (line.empty()) {
            continue;
        }

        const std::size_t delimiterPos = line.find(delimiter);
        if (delimiterPos == std::string::npos || delimiterPos == 0) {
            continue;
        }

        const std::string character = line.substr(0, delimiterPos);
        const std::string distribution = line.substr(delimiterPos + delimiter.length());

        if (character.size() != 1 || distribution.empty()) {
            continue;
        }

        result[character[0]] = std::stof(distribution);
    }

    inFile.close();
    return result;
}
