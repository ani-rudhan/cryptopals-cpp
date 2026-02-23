#include <iostream>
#include <fstream>
#include <sstream>

#include "Base64Decode.hpp"
#include "GetKeysize.hpp"

int main() {
    // std::cout << GetBitwiseHammingDistance("this is a test", "wokka wokka!!!") << std::endl;
    // std::cout << GetCharwiseHammingDistance("this is a test", "wokka wokka!!!") << std::endl;
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
    // std::cout << b64DecStr << std::endl;

    std::cout << "Keysize: " << GetKeysize(b64DecStr) << std::endl;
}