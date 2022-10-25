/**
 * @file HerbCollection.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief HerbCollection
 * @version 0.1
 * @date 2022-10-25
 *
 * @link https://www.luogu.com.cn/problem/P1048
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

// Memorial Search

#include <iostream>
#include <vector>

class HerbCollection {
    int              NumOfHerb = 0;
    int              TimeLimit = 0;
    std::vector<int> Value;
    std::vector<int> TimeCost;

public:
    void input() {
        std::cin >> TimeLimit >> NumOfHerb;

        Value    = std::vector<int>(NumOfHerb);
        TimeCost = std::vector<int>(NumOfHerb);

        for (int x = 0; x < NumOfHerb; ++x) {
            int time_in_need;
            int value;
            std::cin >> time_in_need >> value;
            TimeCost.emplace_back(time_in_need);
            Value.emplace_back(value);
        }
    }
};
