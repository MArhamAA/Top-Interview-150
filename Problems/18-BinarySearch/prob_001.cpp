// BISMILLAH

// Problem link: https://leetcode.com/problems/search-insert-position/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int lo = 0, hi = (int)nums.size()-1, pos = (int)nums.size(), mi;
        while (lo <= hi) {
            mi = lo+(hi-lo)/2;
            int v = nums[mi];
            if (v == target) {
                pos = mi;
                break;
            }
            if (v > target) {
                hi = mi-1;
                pos = mi;
            } else {
                lo = mi+1;
            }
        }

        return pos;
    }
};

signed main() {
    //
}

/*

lower_bound using binary search

*/