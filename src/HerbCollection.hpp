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

#include <cstddef>
#include <iostream>
#include <vector>

class HerbCollection {
    int                           NumOfHerb = 0;
    int                           TimeLimit = 0;
    std::vector<int>              Value;
    std::vector<int>              TimeCost;
    std::vector<std::vector<int>> Memorial;

    int answer = 0;

public:
    void input() {
        std::cin >> TimeLimit >> NumOfHerb;

        Value    = std::vector<int>(static_cast<long>(NumOfHerb * 2));
        TimeCost = std::vector<int>(static_cast<long>(NumOfHerb * 2));

        Memorial = std::vector<std::vector<int>>(
            static_cast<long>(NumOfHerb) * 2,
            std::vector<int>(
                static_cast<long>(TimeLimit) * 2,
                -1
            )
        );

        for (int index = 1; index <= NumOfHerb; ++index) {
            int time_in_need = 0;
            int value        = 0;
            std::cin >> time_in_need >> value;
            TimeCost[index] = time_in_need;
            Value[index]    = value;
        }
    }

    /// @brief worst dfs
    void dfs_func(
        const int& pos,
        const int& time_left,
        const int& curr_value
    ) {
        if (time_left < 0) {
            return;
        }
        if (pos == NumOfHerb + 1) {
            answer = std::max(answer, curr_value);
            return;
        }
        dfs_func(
            pos + 1,
            time_left,
            curr_value
        );
        dfs_func(
            pos + 1,
            time_left - TimeCost[pos],
            curr_value + Value[pos]
        );
    }
    void process() {
        dfs_func(1, TimeLimit, 0);
    }

    /// @brief memorial search
    int memorial_dfs(const int& pos, const int& time_left) {
        if (Memorial[pos][time_left] != -1) {
            return Memorial[pos][time_left];
        }
        if (pos == NumOfHerb + 1) {
            return Memorial[pos][time_left] = 0;
        }

        int unpicked = 0;
        int picked   = 0;

        unpicked = memorial_dfs(pos + 1, time_left);
        if (time_left >= TimeCost[pos]) {
            // you could still pick one herb
            picked = memorial_dfs(pos + 1, time_left - TimeCost[pos]) + Value[pos];
        }

        return Memorial[pos][time_left] = std::max(picked, unpicked);
    }
    void better_process() {
        answer = memorial_dfs(1, TimeLimit);
    }

    void output() {
        std::cout << answer;
    }

    static void solution() {
        HerbCollection TheSolution;
        TheSolution.input();
        TheSolution.better_process();
        TheSolution.output();
    }
};
