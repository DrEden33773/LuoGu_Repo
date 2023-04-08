/**
 * @file EnumAllIndex.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief P1706
 * @version 0.1
 * @date 2022-11-03
 *
 * @link https://www.luogu.com.cn/problem/P1706

 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class EnumAllIndex {
    int max_num = 0;
    // index starts from `1`
    vector<int>        stack;
    unordered_set<int> occurred_num_set;

    void input() {
        cin >> max_num;
        stack.reserve(max_num + 1);
    }
    void dfs(int curr_num, int remained_nums) {
        stack.emplace_back(curr_num);
        occurred_num_set.insert(curr_num);
        --remained_nums;
        if (!remained_nums) {
            // an output
            for (auto&& num : stack) {
                cout << "    " << num;
            }
            cout << endl;
        } else {
            for (int next_num = 1; next_num <= max_num; ++next_num) {
                if (!occurred_num_set.contains(next_num)) {
                    dfs(next_num, remained_nums);
                }
            }
        }
        // current_layer_of_dfs is done!
        // now you have to remove the status of current_layer
        stack.pop_back();
        occurred_num_set.erase(curr_num);
    }
    void process() {
        for (int num = 1; num <= max_num; ++num) {
            dfs(num, max_num);
        }
    }

public:
    static void solution() {
        EnumAllIndex TheSolution;
        TheSolution.input();
        TheSolution.process();
    }
};