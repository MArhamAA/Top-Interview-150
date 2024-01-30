// BISMILLAH

// Problem link: https://leetcode.com/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int N = (int)matrix.size();
        int M = (int)matrix[0].size();

        int val = -1;
        srand(time(0));

        while (val == -1) {
            int pos_new_val = rand()%INT_MAX;
            bool found = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (matrix[i][j] == pos_new_val) {
                        found = 1;
                        break;
                    }
                }
            }
            if (found == 0) {
                val = pos_new_val;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == 0) {

                    for (int ii = 0; ii < N; ii++) {
                        if (matrix[ii][j] != 0) {
                            matrix[ii][j] = val;
                        }
                    }
                    for (int jj = 0; jj < M; jj++) {
                        if (matrix[i][jj] != 0) {
                            matrix[i][jj] = val;
                        }
                    }

                    matrix[i][j] = 0;

                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == val) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};

signed main() {
    //
}

/*

Randomized appraoch, observation
"consant space
time O(N^3) or smth"

*/