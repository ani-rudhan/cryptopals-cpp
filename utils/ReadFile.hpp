#pragma once

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

inline std::string readFileToString(const std::string& path) {
    std::ifstream inFile(path);
    if (!inFile.is_open()) {
        throw std::runtime_error("Unable to open file: " + path);
    }
    std::ostringstream os;
    os << inFile.rdbuf();
    return os.str();
}

inline std::vector<std::string> readFileToLines(const std::string& path) {
    std::ifstream inFile(path);
    if (!inFile.is_open()) {
        throw std::runtime_error("Unable to open file: " + path);
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inFile, line)) {
        lines.push_back(line);
    }
    return lines;
}
