#include <iostream>
#include <fstream>
#include <sstream>

#include "Base64Decode.hpp"
#include "GetKeysize.hpp"
#include "GetKey.hpp"
#include "DecryptUsingRepeatingKeyXOR.hpp"
#include "GetExpectedFreqDistMap.hpp"

#include <vector>
#include <algorithm>
#include <limits>

int main() {
    std::string fileInputStr;
    std::ifstream inFile(BREAK_REPEATING_KEY_XOR_INPUT_FILE_TXT_PATH);
    if (inFile.is_open()) {
        std::ostringstream os;
        os << inFile.rdbuf();
        fileInputStr = os.str();
    } else {
        std::cout << "Unable to open file\n";
    }

    std::string b64DecStr = Base64Decode(fileInputStr);
    auto expectedFreqDistMap = GetExpectedFreqDistMap_LowerCase();

    auto keyDistVec = GetKeysizeCandidates(b64DecStr);

    int candidatesToTry = std::min(5, static_cast<int>(keyDistVec.size()));
    double bestScore = std::numeric_limits<double>::infinity();
    int bestKeySize = -1;
    std::string bestKey;
    std::string bestPlaintext;

    for (int i = 0; i < candidatesToTry; i++) {
        int keySize = keyDistVec[i].first;
        std::string key = GetKey(b64DecStr, keySize);
        std::string plaintext = DecryptUsingRepeatingKeyXOR(b64DecStr, key);
        double score = ScoreEnglishText(plaintext, expectedFreqDistMap);

        if (score < bestScore) {
            bestScore = score;
            bestKeySize = keySize;
            bestKey = key;
            bestPlaintext = plaintext;
        }
    }

    std::cout << "Best keysize: " << bestKeySize << std::endl;
    std::cout << "Best key: " << bestKey << std::endl;
    std::cout << "Best score: " << bestScore << std::endl;
    std::cout << "Plaintext preview:\n" << bestPlaintext.substr(0, 500) << std::endl;
}