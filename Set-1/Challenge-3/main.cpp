#include "singleByteXORCipher.hpp"
#include <iostream>

namespace {
    const std::string hexEncodedString = "7b5a4215415d544115415d5015455447414c155c46155f4058455c5b523f";
}

int main() {
    auto result = GetSingleByteCipher(hexEncodedString);
    std::cout << "Cipher: " << result.first << " Score: " << result.second << std::endl;
}