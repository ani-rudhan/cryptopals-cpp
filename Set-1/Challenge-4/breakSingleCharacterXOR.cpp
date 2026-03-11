/*
    Set 1  Challenge 4:

    Detect single-character XOR
    One of the 60-character strings in this file has been encrypted by single-character XOR.

    Find it.

    (Your code from #3 should help.)
*/
#include "singleByteXORCipher.hpp"
#include <iostream>
#include <fstream>
#include <limits>

int main() {
    std::fstream inFile(BREAK_SINGLE_KEY_XOR_INPUT_FILE_TXT_PATH);
    std::string line = "";
    int counter = 0;
    int sentenceNum = 0;
    int cipher = 0;
    double score = std::numeric_limits<double>::infinity();
    std::string bestPlainText = "";

    while(std::getline(inFile, line)) {
        counter += 1;
        auto resultPair = GetSingleByteCipher(line);
        if (resultPair.second < score) {
            score = resultPair.second;
            sentenceNum = counter;
            cipher = resultPair.first;

            auto decodedLine = HexDecodeToString(line);
            bestPlainText = XorWithSingleByteKey(decodedLine, static_cast<unsigned char>(cipher));
        }
    }

    std::cout << "Sentence " << sentenceNum << " is encrypted with cipher " << cipher << " with chi-square score of " << score << std::endl;
    std::cout << "Best plaintext: " << bestPlainText << std::endl;
}