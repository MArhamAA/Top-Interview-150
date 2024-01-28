// BISMILLAH

// Problem link: https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        bool valid = true;
        // row check
        for (int i = 0; i < 9; i++) {
            bool row[10] = {0};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int cur = board[i][j] - '0';
                if (row[cur]) {
                    valid = 0;
                    break;
                }
                row[cur] = 1;
            }
            if (valid == false) break;
        }
        if (valid) {
            // col check
            for (int j = 0; j < 9; j++) {
                bool col[10] = {0};
                for (int i = 0; i < 9; i++) {
                    if (board[i][j] == '.') continue;
                    int cur = board[i][j] - '0';
                    if (col[cur]) {
                        valid = 0;
                        break;
                    }
                    col[cur] = 1;
                }
                if (valid == false) break;
            }
            if (valid) {
                // sub-matrix check
                for (int i = 0; i < 9; i += 3) {
                    for (int j = 0; j < 9; j += 3) {
                        bool sub[10] = {0};
                        for (int ii = i, c = 0; c < 3; ii++, c++) {
                            for (int jj = j, cc = 0; cc < 3; jj++, cc++) {
                                if (board[ii][jj] == '.') continue;
                                int cur = board[ii][jj]-'0';
                                if (sub[cur]) {
                                    valid = 0;
                                    break;
                                }
                                sub[cur] = 1;
                            }
                            if (valid == false) break;
                        }
                        if (valid == false) break;
                    }
                    if (valid == false) break;
                }
            }
        }

        return valid;
    }
};

signed main() {
    //
}

/*

Implementation

*/