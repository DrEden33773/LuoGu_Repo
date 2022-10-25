/**
 * @file NumberTriangles.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief NumberTriangles
 * @version 0.1
 * @date 2022-10-25
 *
 * @link https://www.luogu.com.cn/problem/P1216
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

// DP => deep to surface
// f(x, y) = max(f(x + 1, y), f(x + 1, y + 1)) + f(x, y)
// f(x_lim, y_lim) = f(x_lim, y_lim)

#include <algorithm>
#include <iostream>
#include <vector>

class NumberTriangles {
    std::vector<std::vector<int>> data;

    int depth  = 0;
    int answer = 0;

public:
    void input() {
        std::cin >> depth;
        data = std::vector<std::vector<int>>(
            depth,
            std::vector<int>(depth)
        );

        for (int x = 0; x < depth; ++x) {
            for (int y = 0; y < x + 1; ++y) {
                int val = 0;
                std::cin >> val;
                data[x][y] = val;
            }
        }
    }
    void iteration_dp() {
        for (int x = depth - 2; x >= 0; --x) {
            for (int y = 0; y < x + 1; ++y) {
                data[x][y] = std::max(data[x + 1][y], data[x + 1][y + 1]) + data[x][y];
            }
        }
        answer = data[0][0];
    }
    void output() {
        std::cout << answer;
    }
    static void solution() {
        NumberTriangles s;
        s.input();
        s.iteration_dp();
        s.output();
    }
};