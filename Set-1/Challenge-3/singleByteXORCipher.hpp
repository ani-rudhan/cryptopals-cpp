/*
    Set 1  Challenge 3:

    Single-byte XOR cipher
    The hex encoded string:

    1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736
    ... has been XOR'd against a single character. Find the key, decrypt the message.

    You can do this by hand. But don't: write code to do it for you.

    How? Devise some method for "scoring" a piece of English plaintext. 
    Character frequency is a good metric. Evaluate each output and choose the one with the best score.
*/
#pragma once

#include "GetExpectedFreqDistMap.hpp"
#include "HexDecode.hpp"
#include "GetCharCount.hpp"

#include <iostream>
#include <map>

std::pair<int, float> GetSingleByteCipher(std::string hexEncodedString) {
    // Get the frequency distribution of english alphabets by scanning a large corpus
    auto expectedFreqDistMap = GetExpectedFreqDistMap_LowerCase();
    
    // Decode the given string
    auto decodedString = HexDecode(hexEncodedString);
    
    // Assign a large value as reference, so that we can track the cipher with lower chi-square value
    float minScore = 1000000.0;
    int cipher = 0;

    // For every ASCII value, XOR each character of the decoded string with the chosen ASCII value
    for (int ascii = 0; ascii <= 255; ascii++) {
        std::string decryptedString = "";

        for (int idx = 0; idx < decodedString.size(); idx++) {
            decryptedString += (decodedString[idx] ^ ascii);
        }

        // Generate a charCount of the characters present in the decrypted string
        auto charCount = GetCharCount_LowerCase(decryptedString);
        
        // Get the total size of the string, so that we could convert the expected freq.dist of alphabets to expected count of alphabets in the decryptedString
        int totalStringLength = decryptedString.size();
        float score = 0.0;

        // For every character in the decoded string, calculate the chi-square score. Accumulate the scores for the entire string
        for (auto itr : charCount) {
            auto asciiValue = static_cast<unsigned char>(itr.first);
            int observed = itr.second;
            
            // check if decryptedString contains printable characters
            if (asciiValue >= 32 && asciiValue <= 126) {
                float expected = 0.0;
                if (expectedFreqDistMap.find(itr.first) != expectedFreqDistMap.end()) {
                    // if the characters are english alphabet, get the expected count
                    expected = ((float)expectedFreqDistMap[itr.first] * totalStringLength);
                } else {
                    // if the characters are non-english alphabet, set a very low expected count (to avoid division by zero in chi-square calculation)
                    expected = (0.00001 * totalStringLength);
                }

                float numerator = (float)(observed - expected);
                score += ((float)(numerator * numerator) / expected);
            } else {
                // if decryptedString contains non-printable characters like whitespace, penalize by inflating the chi-square score
                score += 50.0; 
            }
        }

        // the cipher which produces a decryptedString that closely resembles a typical english sentence/phrase will have the lower chi-square score
        if (score < minScore) {
            minScore = score;
            cipher = ascii;
        }
    }

    // std::cout << "Cipher is : " << cipher << std::endl;
    std::pair<int, float> result = std::make_pair(cipher, minScore);
    return result;
}
