#pragma once

#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>

#include "GetHammingDistance.hpp"

namespace
{
    const int minKeysize = 2;
    const int maxKeysize = 40;
}

int GetKeysize(std::string inputString) {
    std::vector<std::pair<int, float>> keyDistVec;

    for (int keysize = minKeysize; keysize <= maxKeysize; keysize++) {
        std::stack<std::string> adjBlock;
        int numOfBlocks = 0;
        std::string copyOfInputStr(inputString);
        while (copyOfInputStr.size() >= keysize) {
            auto str = copyOfInputStr.substr(0, keysize);
            adjBlock.push(str);
            copyOfInputStr.erase(0, keysize);
            numOfBlocks += 1;
        }

        int sumOfDistances = 0;
        while (!adjBlock.empty())
        {
            auto blkA = adjBlock.top();
            adjBlock.pop();
            if (adjBlock.empty()) { break; }
            auto blkB = adjBlock.top();

            sumOfDistances += GetBitwiseHammingDistance(blkA, blkB);
        }
        
        float avgDist = (float)sumOfDistances / numOfBlocks;
        float normDist = avgDist / keysize;
        
        auto keyDistPair = std::make_pair(keysize, normDist);
        keyDistVec.push_back(keyDistPair);
    }

    std::sort(keyDistVec.begin(), keyDistVec.end(), [](const std::pair<int, float>& a, const std::pair<int, float>& b){
        return a.second < b.second;
    });

    // for (auto itr : keyDistVec) {
    //     std::cout << itr.first << " | " << itr.second << std::endl;
    // }

    return keyDistVec[0].first;
}