// BISMILLAH

// Problem link: https://leetcode.com/problems/single-number/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ans = 0;
        for (auto i : nums) {
            ans ^= i;
        }
        return ans;
    }
};

signed main() {
    //
}

/*

xor value of the whole array
O(1) extra space

*/