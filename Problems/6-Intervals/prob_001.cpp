// BISMILLAH

// Problem link: https://leetcode.com/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        int N = (int)nums.size();
        std::vector<std::string> ans;

        if (N == 0) return ans;

        int L, R;
        std::string s;

        for (int i = 0; i < N; i++) {
            if (i == 0) {
                L = R = nums[i];
            } else if (nums[i]-1 != nums[i-1]) {
                if (L == R) {
                    ans.push_back(std::to_string(L));
                } else {
                    s = std::to_string(L);
                    s += "->";
                    s += std::to_string(R);
                    ans.push_back(s);
                }
                L = R = nums[i];
            } else {
                R = nums[i];
            }
        }
        if (L == R) {
            ans.push_back(std::to_string(L));
        } else {  // L != R
            s = std::to_string(L);
            s += "->";
            s += std::to_string(R);
            ans.push_back(s);
        }

        return ans;
    }
};

signed main() {
    //
}

/*

Implementation

*/