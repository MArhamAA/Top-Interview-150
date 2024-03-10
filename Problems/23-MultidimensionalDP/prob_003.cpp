// BISMILLAH

// Problem link: https://leetcode.com/problems/unique-paths-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int N = (int)g.size();
        int M = (int)g[0].size();
        int dp[N+1][M+1];
        dp[0][0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (g[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == j && i == 0) continue;
                int fi = i ? dp[i-1][j] : 0;
                int se = j ? dp[i][j-1] : 0;
                dp[i][j] = fi+se;
            }
        }

        return dp[N-1][M-1];
    }
};

signed main() {
    //
}

/*

grid path classic dp problem

*/