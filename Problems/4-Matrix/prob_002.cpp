// BISMILLAH

// Problem link: https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int N = (int)matrix.size();
        int M = (int)matrix[0].size();
        int d = 0, row[2], col[2];
        row[0] = 0, row[1] = N-1;
        col[0] = 0, col[1] = M-1;
        std::vector<int> ans(N*M);
        int idx = 0;

        while (row[0] <= row[1] && col[0] <= col[1]) {
            d %= 4;
            if (d == 0) {
                for (int i = col[0]; i <= col[1]; i++) {
                    ans[idx++] = matrix[row[0]][i];
                }
                row[0]++;
            } else if (d == 1) {
                for (int i = row[0]; i <= row[1]; i++) {
                    ans[idx++] = matrix[i][col[1]];
                }
                col[1]--;
            } else if (d == 2) {
                for (int i = col[1]; i >= col[0]; i--) {
                    ans[idx++] = matrix[row[1]][i];
                }
                row[1]--;
            } else {
                for (int i = row[1]; i >= row[0]; i--) {
                    ans[idx++] = matrix[i][col[0]];
                }
                col[0]++;
            }
            d++;
        }
        
        return ans;
    }
};

signed main() {
    //
}

/*

Implementation

using loop

*/