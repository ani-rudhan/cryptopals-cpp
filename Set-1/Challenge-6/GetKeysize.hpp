#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include "GetHammingDistance.hpp"

namespace
{
    const int minKeysize = 2;
    const int maxKeysize = 40;
}

inline std::vector<std::pair<int, double>> GetKeysizeCandidates(const std::string &inputString) {
    std::vector<std::pair<int, double>> keyDistVec;

    for (int keysize = minKeysize; keysize <= maxKeysize; keysize++) {
        std::vector<std::string> blocks;
        const int maxBlocks = 8;
        for (int i = 0; i < maxBlocks; i++) {
            int start = i * keysize;
            if (start + keysize > static_cast<int>(inputString.size())) {
                break;
            }
            blocks.push_back(inputString.substr(start, keysize));
        }

        if (blocks.size() < 2) {
            continue;
        }

        double sumNormDist = 0.0;
        int numOfComparisons = 0;
        for (int i = 0; i < static_cast<int>(blocks.size()); i++) {
            for (int j = i + 1; j < static_cast<int>(blocks.size()); j++) {
                int dist = GetBitwiseHammingDistance(blocks[i], blocks[j]);
                if (dist >= 0) {
                    sumNormDist += static_cast<double>(dist) / static_cast<double>(keysize);
                    numOfComparisons += 1;
                }
            }
        }

        if (numOfComparisons == 0) {
            continue;
        }

        keyDistVec.emplace_back(keysize, sumNormDist / static_cast<double>(numOfComparisons));
    }

    std::sort(keyDistVec.begin(), keyDistVec.end(), [](const std::pair<int, double> &a, const std::pair<int, double> &b) {
        return a.second < b.second;
    });

    return keyDistVec;
}

inline int GetKeysize(const std::string &inputString) {
    auto keyDistVec = GetKeysizeCandidates(inputString);

    if (keyDistVec.empty()) {
        return -1;
    }

    return keyDistVec[0].first;
}