// BISMILLAH

// Problem link: https://leetcode.com/problems/3sum/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    int N = (int)nums.size(), sum, first, second;
    sort(nums.begin(), nums.end());
    std::set<std::vector<int>> ans;
    for (int i = 0; i < N-2; i++) {
        sum = 0-nums[i];
        first = i+1, second = N-1;
        for (; first < second; first++) {
            while (nums[first] + nums[second] > sum && first < second) second--;
            if (nums[first] + nums[second] == sum && first < second) {
                ans.insert({nums[i], nums[first], nums[second]});
                // first++;
            }
        }
    }
    
    std::vector<std::vector<int>> fin;
    for (auto i : ans) fin.push_back(i);
    return fin;
}

signed main() {
    //
}

/*

TwoSum, sorting and outer loop
O(N*N) time

*/