// BISMILLAH

// Problem link: https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, std::vector<int>> list;
        int N = (int)nums.size();
        for (int i = 0; i < N; i++) {
            list[nums[i]].push_back(i);
        }
        for (auto i : list) {
            N = (int)i.second.size();
            for (int j = 0; j < N-1; j++) {
                if (i.second[j+1]-i.second[j] <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};

signed main() {
    //
}

/*

2D Freq Array

*/