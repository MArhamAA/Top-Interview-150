// BISMILLAH

// Problem link: https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int N = (int)nums.size();
        if (N == 1) return nums[0];
        int dp[3];
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < N; i++) {
            dp[2] = std::max(dp[1], dp[0] + nums[i]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return std::max(dp[1], dp[2]);
    }
};

signed main() {
    //
}

/*

prefix based best ans
state optimization

*/