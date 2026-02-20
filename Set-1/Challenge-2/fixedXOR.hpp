/*
    Set 1  Challenge 2:

    Fixed XOR
    Write a function that takes two equal-length buffers and produces their XOR combination.

    If your function works properly, then when you feed it the string:

    1c0111001f010100061a024b53535009181c
    ... after hex decoding, and when XOR'd against:

    686974207468652062756c6c277320657965
    ... should produce:

    746865206b696420646f6e277420706c6179
*/

#include <iostream>
#include <string>
#include <bitset>
#include <sstream>

std::string fixedLengthXOR(const std::string stringA, const std::string stringB)
{
    std::string xorResult = "";

    for (auto itrA = stringA.begin(), itrB = stringB.begin(); ;itrA++,itrB++)
    {
        if ((itrA == stringA.end()) && (itrB == stringB.end()))
        {
            break;
        }

        auto binA = std::bitset<4>(std::stoul(std::string(1, *itrA), nullptr, 16));
        auto binB = std::bitset<4>(std::stoul(std::string(1, *itrB), nullptr, 16));
        auto binC = binA ^ binB;
        std::stringstream ss;
        ss << std::hex << binC.to_ulong();
        xorResult += ss.str();
    }

    return xorResult;
}
