// BISMILLAH

// Problem link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int lo = 1, hi = (int)nums.size()-1, mi;
        if (nums[0] < nums[hi]) {
            return nums[0];
        }
        int ans, last = nums[hi];
        while (lo <= hi) {
            mi = lo+(hi-lo)/2;
            int u = nums[mi], v = nums[mi-1];
            if (u < v) {
                ans = u;
                break;
            }
            if (u > v && v < last) {
                ans = v;
                hi = mi-1;
            } else {
                lo = mi+1;
            }
        }

        return ans;
    }
};

signed main() {
    //
}

/*

two binary search on first and second part

*/