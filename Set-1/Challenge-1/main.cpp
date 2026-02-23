#include "hexToBase64.hpp"
#include "Base64Encode.hpp"
#include "Base64Decode.hpp"
#include <iostream>

namespace {
    const std::string inputStr = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
}

int main()
{
    std::cout << "Encoded String : " << hexToBase64(inputStr) << std::endl;
}