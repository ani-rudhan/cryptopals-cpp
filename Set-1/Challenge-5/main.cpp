#include <string>
#include <iostream>

#include "repeatingKeyXOR.hpp"

// Burning 'em, if you ain't quick and nimble
// I go crazy when I hear a cymbal
namespace {
    const std::string inputString = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
    
    const std::string key = "ICE";
}
int main() {
    std::cout << "Encrypted string : " << EncryptUsingRepearingKeyXOR(inputString, key) << std::endl;
}