// BISMILLAH

// Problem link: https://leetcode.com/problems/triangle/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int N = (int)triangle.size();
        int dp[N][N];
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < N; i++) {
            int M = i+1;
            int val = triangle[i][0];
            dp[i][0] = dp[i-1][0] + val;
            for (int j = 1; j < M-1; j++) {
                val = triangle[i][j];
                dp[i][j] = std::min(dp[i-1][j], dp[i-1][j-1])+val;
            }
            val = triangle[i][M-1];
            dp[i][M-1] = dp[i-1][M-2] + val;
        }
        int ans = INT_MAX;
        for (int i = 0; i < N; i++) {
            ans = std::min(ans, dp[N-1][i]);
        }
        return ans;
    }
};

signed main() {
    //
}

/*

fibonacci seq type memo

*/