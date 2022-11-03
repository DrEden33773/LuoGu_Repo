/**
 * @file P_1002.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief P_1002
 * @version 0.1
 * @date 2022-10-25
 *
 * @link https://www.luogu.com.cn/problem/P1002
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <iostream>
#include <set>
#include <vector>

class P_1002 {
    std::set<std::pair<long long, long long>> control_point;
    std::pair<long long, long long>           destination;
    std::pair<long long, long long>           horse_point;
    std::vector<std::vector<long long>>       dp_arr;

    long long answer = 0;

public:
    void input() {
        long long des_X   = 0;
        long long des_Y   = 0;
        long long horse_X = 0;
        long long horse_Y = 0;

        std::cin >> des_X >> des_Y >> horse_X >> horse_Y;

        destination = std::make_pair(des_X, des_Y);
        horse_point = std::make_pair(horse_X, horse_Y);

        auto& h = horse_point;
        auto& c = control_point;
        c.insert(h);
        c.insert(std::make_pair(h.first - 2, h.second + 1));
        c.insert(std::make_pair(h.first - 1, h.second + 2));
        c.insert(std::make_pair(h.first + 1, h.second + 2));
        c.insert(std::make_pair(h.first + 2, h.second + 1));
        c.insert(std::make_pair(h.first - 2, h.second - 1));
        c.insert(std::make_pair(h.first - 1, h.second - 2));
        c.insert(std::make_pair(h.first + 1, h.second - 2));
        c.insert(std::make_pair(h.first + 2, h.second - 1));
    }

    /// @brief @b recursive_dp
    long long DP_FUNC(const long long& x, const long long& y) {
        if (control_point.find(std::make_pair(x, y)) != control_point.end()) {
            // find both coordinates!
            return 0;
        }
        if (!x && !y) {
            return 1;
        } else if (!x) {
            return DP_FUNC(x, y - 1);
        } else if (!y) {
            return DP_FUNC(x - 1, y);
        }
        return DP_FUNC(x - 1, y) + DP_FUNC(x, y - 1);
    }
    void recursive_dp_solution() {
        answer = DP_FUNC(destination.first, destination.second);
    }

    /// @brief @b iteration_dp
    void iteration_dp_solution() {
        // 1. init dp_arr
        dp_arr = std::vector<std::vector<long long>>(
            destination.first + 1,
            std::vector<long long>(destination.second + 1, 0)
        );

        long long X = destination.first;
        long long Y = destination.second;
        for (long long x = 0; x <= X; ++x) {
            for (long long y = 0; y <= Y; ++y) {
                if (control_point.find(std::make_pair(x, y)) != control_point.end()) {
                    // find both coordinates!
                    dp_arr[x][y] = 0;
                } else {
                    if (!x && !y) {
                        dp_arr[x][y] = 1;
                    } else if (!x) {
                        dp_arr[x][y] = dp_arr[x][y - 1];
                    } else if (!y) {
                        dp_arr[x][y] = dp_arr[x - 1][y];
                    } else {
                        dp_arr[x][y] = dp_arr[x][y - 1] + dp_arr[x - 1][y];
                    }
                }
            }
        }

        answer = dp_arr[X][Y];
    }

    void output() {
        std::cout << answer;
    }
    static void solution() {
        P_1002 TheSolution;
        TheSolution.input();
        TheSolution.iteration_dp_solution();
        TheSolution.output();
    }
};