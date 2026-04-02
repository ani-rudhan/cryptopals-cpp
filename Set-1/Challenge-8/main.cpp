/*
    Detect AES in ECB mode
    In this file are a bunch of hex-encoded ciphertexts.

    One of them has been encrypted with ECB.

    Detect it.

    Remember that the problem with ECB is that it is stateless and deterministic; the same 16 byte plaintext block will always produce the same 16 byte ciphertext.
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

#include "HexDecode.hpp"
#include "ReadFile.hpp"

int NumberOfDuplicates(std::vector<std::string> string_array) {
    int counter = 0;
    for (int i = 0; i < string_array.size(); i++) {
        std::string ref_str = string_array[i];
        for (int j = i + 1; j < string_array.size(); j++) {
            if (ref_str == string_array[j]) {
                counter += 1;
            }
        }
    }
    return counter;
}

int main() {
    auto lines = readFileToLines(DETECT_AES_ECB_ENCRYPTED_FILE_TXT_PATH);

    int num_of_lines = lines.size();
    std::map<int, int> duplicate_blks_per_line;

    for (int i = 0; i <  num_of_lines; i++) {
        std::vector<std::string> blk_split_strings;
        int idx = 0;

        for (int j = 0; j < 16; j++) {
            blk_split_strings.push_back(lines[i].substr(idx, 16));
            idx += 16;
        }

        duplicate_blks_per_line[i + 1] = NumberOfDuplicates(blk_split_strings);
    }

    for (auto [linenum, dup] : duplicate_blks_per_line) {
        if (dup != 0) {
            std::cout << "Line number "<< linenum << " has " << dup << " duplicates\n";
        }
    }
}