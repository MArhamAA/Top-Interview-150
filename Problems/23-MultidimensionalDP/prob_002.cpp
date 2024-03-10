// BISMILLAH

// Problem link: https://leetcode.com/problems/minimum-path-sum/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int N = (int)grid.size();
        int M = (int)grid[0].size();
        int dp[N+1][M+1];
        dp[0][0] = grid[0][0];
        int inf = 1e9;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (i == j && i == 0) continue;
                int fi = i ? dp[i-1][j] : inf;
                int se = j ? dp[i][j-1] : inf;
                dp[i][j] = std::min(fi,se) + grid[i][j];
            }
        }

        return dp[N-1][M-1];
    }
};

signed main() {
    //
}

/*

grid path sum classic dp problem

*/