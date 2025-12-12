/*  
    Set 1  Challenge 1:

    Convert hex to base64
    The string:

    49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d
    Should produce:

    SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t
    So go ahead and make that happen. You'll need to use this code for the rest of the exercises.

    Cryptopals Rule
    Always operate on raw bytes, never on encoded strings. Only use hex and base64 for pretty-printing.
*/

#include <iostream>
#include <bitset>
#include <string>
#include <sstream>

namespace {
    const std::string inputStr = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    const std::string base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
}

std::string hexToBase64(const std::string &hexStr)
{
    std::string base64EncodedStr = "";
    std::string binaryStr = "";
    
    for (auto itr = hexStr.begin(); itr != hexStr.end(); itr++)
    {
        auto hexToInt = std::stoul(std::string(1, *itr), nullptr, 16);
        binaryStr += std::bitset<4>(hexToInt).to_string();
    }

    for (auto i = 0; i < binaryStr.length(); i += 6)
    {
        std::stringstream sixBitBinStr(binaryStr.substr(i, 6));
        std::bitset<6> bits;
        sixBitBinStr >> bits;
        base64EncodedStr += base64Chars[bits.to_ulong()];
    }

    int paddingCnt = 0;
    if ((base64EncodedStr.length() % 4) == 0)
    {
        auto paddingCnt = 4 - (base64EncodedStr.length() % 4);
    }

    for (auto i = 0; i < paddingCnt; i++)
    {
        base64EncodedStr += "=";
    }

    return base64EncodedStr;
}

int main()
{
    std::cout << "Encoded String : " << hexToBase64(inputStr) << std::endl;
}