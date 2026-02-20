#include "singleByteXORCipher.hpp"
#include <iostream>
#include <fstream>

int main() {
    std::fstream inFile(SINGLE_CHAR_XOR_INPUT_FILE_TXT_PATH);
    std::string line = "";
    int counter = 0;
    int sentenceNum = 0;
    int cipher = 0;
    float score = 100000.0;

    while(std::getline(inFile, line)) {
        counter += 1;
        auto resultPair = GetSingleByteCipher(line);
        std::cout << counter << " cipher: " << resultPair.first << " score: " << resultPair.second << std::endl;
        if (resultPair.second < score) {
            score = resultPair.second;
            sentenceNum = counter;
            cipher = resultPair.first;
        }
    }

    std::cout << "Sentence " << sentenceNum << " is encrypted with cipher " << cipher << " with chi-square score of " << score << std::endl;
}