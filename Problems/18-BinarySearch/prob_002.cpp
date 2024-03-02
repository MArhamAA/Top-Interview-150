// BISMILLAH

// Problem link: https://leetcode.com/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int N = (int)matrix.size()-1, M = (int)matrix[0].size()-1;
        bool ans = false;

        int lo = 0, hi = N, mi, row = -1;
        while (lo <= hi) {
            mi = lo+(hi-lo)/2;
            int v = matrix[mi][0];
            if (v <= target) {
                row = mi;
                lo = mi+1;
            } else {
                hi = mi-1;
            }
        }

        if (row != -1) {
            lo = 0, hi = M;
            while (lo <= hi) {
                mi = lo+(hi-lo)/2;
                int v = matrix[row][mi];
                if (v == target) {
                    ans = true;
                    break;
                }
                if (v < target) {
                    lo = mi+1;
                } else {
                    hi = mi-1;
                }
            }
        }

        return ans;
    }
};

signed main() {
    //
}

/*

first find the row, then search in col

*/