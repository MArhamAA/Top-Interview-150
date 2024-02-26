// BISMILLAH

// Problem link: https://leetcode.com/problems/permutations/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::vector<int> cur;
    std::unordered_map<int,bool> taken;

    void fn(std::vector<int>& a, std::vector<std::vector<int>>& b) {
        if ((int)cur.size() == (int)a.size()) {
            b.push_back(cur);
            return;
        }
        for (int i : a) {
            if (taken[i] == 0) {
                taken[i] = 1;
                cur.push_back(i);
                fn(a, b);
                taken[i] = 0;
                cur.pop_back();
            }
        }
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        fn(nums, ans);
        return ans;
    }
};

signed main() {
    //
}

/*

backtrack, recursion, permutation

*/