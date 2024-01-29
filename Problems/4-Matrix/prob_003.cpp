// BISMILLAH

// Problem link: https://leetcode.com/problems/rotate-image/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int N = (int)matrix.size();

        if (N==1) return;

        int a[N-1];
        for (int I = 0; I < N/2; I++) {
            // copy, rechange 4 times
            for (int j = I; j < N-I-1; j++) {
                a[j-I] = matrix[I][j];
            }
            for (int i = I; i < N-I-1; i++) {
                std::swap(a[i-I], matrix[i][N-I-1]);
            }

            for (int j = N-I-1; j > I; j--) {
                std::swap(a[(N-I-1)-j], matrix[N-I-1][j]);
            }

            for (int i = N-I-1; i > I; i--) {
                std::swap(a[(N-I-1)-i], matrix[i][I]);
            }

            for (int j = I; j < N-I-1; j++) {
                std::swap(a[j-I], matrix[I][j]);
            }
        }
    }
};

signed main() {
    //
}

/*

Implementation
in-place

*/