// BISMILLAH

// Problem link: https://leetcode.com/problems/maximal-square/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int M = (int)matrix.size();
        int N = (int)matrix[0].size();
        bool dp[M][N][std::min(M, N)+1];
        memset(dp,0,sizeof(dp));

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == '0') continue;
                dp[i][j][1] = 1;
                for (int sq = 2; sq <= std::min(i,j)+1; sq++) {
                    if (i-1 >= 0 && j-1 >= 0) {
                       dp[i][j][sq] |= dp[i-1][j-1][sq-1] & dp[i-1][j][sq-1] & dp[i][j-1][sq-1];
                    }
                }
            }
        }
        
        int ans=0;
        for (int sq = std::min(M,N); sq; sq--) {
            for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) {
                if (dp[i][j][sq]) {
                    ans = std::max(ans, sq);
                }
            }
        }
        return ans*ans;
    }
};

signed main() {
    //
}

/*

observation, dp on size of squares
2D pref_sum concept

*/