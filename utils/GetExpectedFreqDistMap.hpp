#pragma once

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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

    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string character;
        std::string distribution;
        if (std::getline(ss, character, ',')) {
            if (std::getline(ss, distribution)) {
                char c = character[0];
                result[c] = std::stof(distribution);
            }
        }
    }

    inFile.close();
    return result;
}