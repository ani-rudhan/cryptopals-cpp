#include <string>
#include <iostream>

#include "fixedXOR.hpp"

namespace
{
    const std::string stringA = "1c0111001f010100061a024b53535009181c";
    const std::string stringB = "686974207468652062756c6c277320657965";
}

int main()
{
    std::cout << fixedLengthXOR(stringA, stringB) << std::endl;
}