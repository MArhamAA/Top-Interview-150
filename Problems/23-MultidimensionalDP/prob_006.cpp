// BISMILLAH

// Problem link: https://leetcode.com/problems/edit-distance/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = (int)word1.size();
        int M = (int)word2.size();
        int dp[N+1][M+1];

        // base case
        dp[0][0] = 0;
        for (int i = 1; i <= N; i++) dp[i][0] = i;
        for (int j = 1; j <= M; j++) dp[0][j] = j;

        for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
            int ans = INT_MAX;
            if (word1[i-1] == word2[j-1]) {
                ans = min(ans, dp[i-1][j-1]);
            } else {
                // insertion
                ans = std::min(ans, dp[i][j-1]+1);

                // deletion
                ans = std::min(ans, dp[i-1][j]+1);

                // replacement
                ans = std::min(ans, dp[i-1][j-1]+1);
            }
            dp[i][j] = ans;
        }

        return dp[N][M];
    }
};

signed main() {
    //
}

/*

edit distance classic dp: insert,del,replace

*/