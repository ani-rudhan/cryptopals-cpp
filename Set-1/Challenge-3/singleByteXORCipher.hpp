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
#include <limits>
#include <cctype>

inline std::string XorWithSingleByteKey(const std::string &input, unsigned char key)
{
    std::string out;
    out.reserve(input.size());

    for (unsigned char c : input)
    {
        out.push_back(static_cast<char>(c ^ key));
    }

    return out;
}

inline double ScoreEnglishText(const std::string &candidate, const std::map<char, float> &expectedFreqDistMap)
{
    if (candidate.empty())
    {
        return std::numeric_limits<double>::infinity();
    }

    auto charCount = GetCharCount_LowerCase(candidate);

    int allowedCount = 0;
    int nonPrintableCount = 0;
    int weirdPrintableCount = 0;

    for (unsigned char ch : candidate)
    {
        if ((ch < 32 || ch > 126) && ch != '\n' && ch != '\r' && ch != '\t')
        {
            nonPrintableCount += 1;
            continue;
        }

        char lower = static_cast<char>(std::tolower(ch));
        if (expectedFreqDistMap.find(lower) != expectedFreqDistMap.end())
        {
            allowedCount += 1;
            continue;
        }

        if (!std::isdigit(ch) && ch != '.' && ch != ',' && ch != '\'' && ch != '!' && ch != '?' && ch != ':' && ch != ';' && ch != '-')
        {
            weirdPrintableCount += 1;
        }
    }

    if (allowedCount == 0)
    {
        return std::numeric_limits<double>::infinity();
    }

    double score = 0.0;
    for (auto const &[alphabet, expectedProb] : expectedFreqDistMap)
    {
        int observed = 0;
        auto it = charCount.find(alphabet);
        if (it != charCount.end())
        {
            observed = it->second;
        }

        double expected = static_cast<double>(expectedProb) * static_cast<double>(allowedCount);
        if (expected > 0.0)
        {
            double diff = static_cast<double>(observed) - expected;
            score += (diff * diff) / expected;
        }
    }

    score += static_cast<double>(nonPrintableCount) * 250.0;
    score += static_cast<double>(weirdPrintableCount) * 20.0;

    return score;
}

inline std::pair<int, double> GetSingleByteCipher(const std::string &hexEncodedString)
{
    // Get the frequency distribution of english alphabets by scanning a large corpus
    auto expectedFreqDistMap = GetExpectedFreqDistMap_LowerCase();

    // Decode the given string
    auto decodedString = HexDecodeToString(hexEncodedString);

    // Lower chi-square is a better fit for English-like plaintext.
    double minScore = std::numeric_limits<double>::infinity();
    int cipher = -1;

    // For every ASCII value, XOR each character of the decoded string with the chosen ASCII value
    for (int ascii = 0; ascii <= 255; ascii++)
    {
        auto decryptedString = XorWithSingleByteKey(decodedString, static_cast<unsigned char>(ascii));
        double score = ScoreEnglishText(decryptedString, expectedFreqDistMap);

        // std::cout << "Score: " << score << " Ascii: " << ascii << std::endl;
        // the cipher which produces a decryptedString that closely resembles a typical english sentence/phrase will have the lower chi-square score
        if (score < minScore)
        {
            minScore = score;
            cipher = ascii;
        }
    }

    // std::cout << "Cipher is : " << cipher << std::endl;
    std::pair<int, double> result = std::make_pair(cipher, minScore);
    return result;
}
