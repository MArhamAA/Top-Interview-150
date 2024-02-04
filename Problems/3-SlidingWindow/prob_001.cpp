// BISMILLAH

// Problem link: https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

int minSubArrayLen(int target, std::vector<int>& nums) {
    int N = (int)nums.size();
    int ans = N+1, first = 0, sum = 0;
    for (int second = 0; second < N; second++) {
        sum += nums[second];
        while (sum-nums[first] >= target && first <= second) {
            sum -= nums[first++];
        }
        if (sum >= target) {
            ans = std::min(ans, second-first+1);
        }
    }

    return ans > N ? 0 : ans;
}

signed main() {
    //
}

/*

Maintain a window, O(N) time

"O(N lg N) time
binary-search
& prefix-sum"

*/