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
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class P_1002 {
    unordered_set<int> X_control;
    unordered_set<int> Y_control;
    pair<int, int>     destination;
    pair<int, int>     horse_point;

public:
    void input() {
        int des_X, des_Y;
        int horse_X, horse_Y;

        cin >> des_X >> des_Y >> horse_X >> horse_Y;

        destination = make_pair(des_X, des_Y);
        horse_point = make_pair(horse_X, horse_Y);

        X_control.insert(horse_point.first);
        Y_control.insert(horse_point.second);

        X_control.insert(horse_point.first - 2);
        Y_control.insert(horse_point.second + 1);

        X_control.insert(horse_point.first - 1);
        Y_control.insert(horse_point.second + 2);

        X_control.insert(horse_point.first + 1);
        Y_control.insert(horse_point.second + 2);

        X_control.insert(horse_point.first + 2);
        Y_control.insert(horse_point.second + 1);

        X_control.insert(horse_point.first - 2);
        Y_control.insert(horse_point.second - 1);

        X_control.insert(horse_point.first - 1);
        Y_control.insert(horse_point.second - 2);

        X_control.insert(horse_point.first + 1);
        Y_control.insert(horse_point.second - 2);

        X_control.insert(horse_point.first + 2);
        Y_control.insert(horse_point.second - 1);
    }
    int DP_FUNC(const int& x, const int& y) {
        if (X_control.find(x) != X_control.end()
            && Y_control.find(y) != Y_control.end()) {
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
    void output() {
        auto&& d   = destination;
        auto&& res = DP_FUNC(destination.first, destination.second);
        cout << res;
    }
    static void solution() {
        P_1002 TheSolution;
        TheSolution.input();
        TheSolution.output();
    }
};