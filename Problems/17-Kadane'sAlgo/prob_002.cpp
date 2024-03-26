// BISMILLAH

// Problem link: https://leetcode.com/problems/maximum-sum-circular-subarray/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int N = (int)nums.size();
        int ans = INT_MIN, sum = 0;

        // basic kadane's
        for (int i : nums) {
            sum = std::max(i, sum+i);
            ans = std::max(ans, sum);
        }

        // pref max upto i
        int pref[N];
        pref[0] = nums[0]; sum = nums[0];
        for (int i = 1; i < N; i++) {
            sum += nums[i];
            pref[i] = std::max(pref[i-1], sum);
        }

        // suf max from i
        int suf[N];
        sum = suf[N-1] = nums.back();
        for (int i = N-2; i >= 0; i--) {
            sum += nums[i];
            suf[i] = std::max(suf[i+1], sum);
        }

        for (int i = 0; i < N-1; i++) {
            ans = std::max(ans, pref[i]+suf[i+1]);
        }

        return ans;
    }
};

signed main() {
    //
}

/*

kadane's algo; pref, suf max calculation

*/