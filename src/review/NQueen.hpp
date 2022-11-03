/**
 * @file NQueen.hpp (ComeFrom LeetCode)
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class NQueen {
    vector<int>            queen;
    unordered_set<int>     col;
    unordered_set<int>     main_diag;
    unordered_set<int>     sub_diag;
    vector<string>         board;
    vector<vector<string>> all_board;
    int                    num_of_solution = 0;

public:
    void traverse(const int& row_lim, const int& curr_row = 0) {
        const int& col_lim = row_lim;
        if (curr_row == row_lim) {
            all_board.push_back(gen_a_board(row_lim));
            ++num_of_solution;
        } else {
            for (int curr_col = 0; curr_col < col_lim; ++curr_col) {
                // detect if conflict
                if (col.find(curr_col) != col.end()) {
                    continue;
                }
                int curr_main_diag = curr_col - curr_row;
                if (main_diag.find(curr_main_diag) != main_diag.end()) {
                    continue;
                }
                int curr_sub_diag = curr_col + curr_row;
                if (sub_diag.find(curr_sub_diag) != sub_diag.end()) {
                    continue;
                }

                // no conflict, add info first
                queen[curr_row] = curr_col;
                col.insert(curr_col);
                main_diag.insert(curr_main_diag);
                sub_diag.insert(curr_sub_diag);

                // DFS, to the next
                traverse(row_lim, curr_row + 1);

                // after quitted the DFS for `reach lim` or `conflicted`
                // should delete the `last info of the biggest row`
                // because we will try another `col` on that `biggest row` again
                queen[curr_row] = -1;
                col.erase(curr_col);
                main_diag.erase(curr_main_diag);
                sub_diag.erase(curr_sub_diag);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        col       = unordered_set<int>(n);
        main_diag = unordered_set<int>(n);
        sub_diag  = unordered_set<int>(n);
        board     = vector<string>(n);
        queen     = vector<int>(n, -1); // default value = 1

        return all_board;
    }
    vector<string> gen_a_board(const int& n) {
        vector<string> board;
        board.reserve(n);
        for (int i = 0; i < n; i++) {
            string row(n, '.');
            int&   col = queen[i];
            row[col]   = 'Q';
            board.emplace_back(row);
        }
        return board;
    }
};