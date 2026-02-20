#pragma once

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::map<char, float> GetExpectedFreqDistMap_LowerCase(std::string filepathname = "") {
    if (filepathname.empty()) {
        filepathname = FREQ_DIST_PATH;
    }

    std::ifstream inFile(filepathname);
    std::map<char, float> result;

    // Check if the file was opened successfully
    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return result; // Exit program with error
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        std::string character;
        std::string distribution;
        // 1. Extract up to the first comma
        if (std::getline(ss, character, ',')) {
            // 2. Extract the remainder of the line
            if (std::getline(ss, distribution)) {
                char c = *character.c_str();
                result[c] = std::stof(distribution);
            }
        }
    }

    inFile.close();
    return result;
}