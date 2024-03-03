// BISMILLAH

// Problem link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int lo = 0, hi = (int)nums.size()-1, mi, L=-1, R=(int)nums.size();
        while (lo <= hi) {
            mi = lo+(hi-lo)/2;
            if (nums[mi] < target) {
                L = mi;
                lo = mi+1;
            } else {
                hi = mi-1;
            }
        }
        lo = 0, hi = (int)nums.size()-1;
        while (lo <= hi) {
            mi = lo+(hi-lo)/2;
            if (nums[mi] <= target) {
                lo = mi+1;
            } else {
                hi = mi-1;
                R = mi;
            }
        }

        L++, R--;
        if (L > R) L = R = -1;
        return {L,R};
    }
};

signed main() {
    //
}

/*

lower_bound, upper_bound concept

*/