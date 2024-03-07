// BISMILLAH

// Problem link: https://leetcode.com/problems/coin-change/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int local = 1e9;
            for (int c : coins) {
                if (i-c >= 0) {
                    local = std::min(local, dp[i-c]+1);
                }
            }
            dp[i] = local;
        }
        int ans = dp[amount];
        return ans >= 1e9 ? -1 : ans;
    }
};

signed main() {
    //
}

/*

try with each coin (coin change classicDP)

*/