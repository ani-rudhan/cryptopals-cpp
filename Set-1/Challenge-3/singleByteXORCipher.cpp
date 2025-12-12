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

#include <iostream>
#include <sstream>
#include <bitset>

namespace
{
    const std::string hexEncStr = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
}

int main()
{
    for (auto itr = hexEncStr.begin(); itr != hexEncStr.end(); itr++)
    {
        std::bitset<8>(std::stoul(std::string(1, *itr), nullptr, 16));
    }
}
/*
    For Single-Byte XOR (Key length = 1)
    Method: Treat it like a simple substitution cipher.
    Process:
    Brute-Force: XOR the ciphertext with every possible byte (0-255) to generate 256 potential plaintexts.
    Evaluate: Score each output for how closely it resembles natural language (English, etc.) using metrics like:
    Letter Frequencies: Does 'E', 'T', 'A', 'O', 'I', 'N' appear most often?
    Common Digraphs/Trigraphs: Do frequent English letter combinations appear?
    Fitting Quotient: Calculate the average absolute difference between character frequencies in the decrypted text and known language frequencies.
    Identify: The key that yields the highest score (most "English-like" text) is likely the correct key
*/