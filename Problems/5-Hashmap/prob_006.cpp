// BISMILLAH

// Problem link: https://leetcode.com/problems/two-sum/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int N = (int)nums.size();
        std::unordered_map<int,std::vector<int>> idx;
        for (int i = 0; i < N; i++) {
            idx[nums[i]].push_back(i);
        }
        sort(nums.begin(), nums.end());
        int first = 0, second;
        for (second = N-1; second > first; second--) {
            while (nums[first] + nums[second] < target && first < second) {
                first++;
            }
            if (first < second && nums[first]+nums[second] == target) {
                break;
            }
        }
        std::vector<int> ans;
        ans.push_back(idx[nums[first]].back());
        idx[nums[first]].pop_back();
        ans.push_back(idx[nums[second]].back());
        return ans;
    }
};

signed main() {
    //
}

/*

O(N lgN)

*/