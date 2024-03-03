// BISMILLAH

// Problem link: https://leetcode.com/problems/find-peak-element/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int lo = 0, hi = (int)nums.size()-1, mi, ans;
        while (lo <= hi) {
            mi = lo+(hi-lo)/2;
            bool fi, se;
            fi = mi ? nums[mi]>nums[mi-1] : 1;
            se = mi == nums.size()-1 ? 1 : nums[mi]>nums[mi+1];
            if (fi&&se) {
                ans = mi;
                break;
            }
            if (fi) {
                lo = mi+1;
            } else {
                hi = mi-1;
            }
        }

        return ans;
    }
};

signed main() {
    //
}

/*

"Assume, all num is distinct. Binary search 
on array indices. If left part is ok then go 
right side or vice versa. If both part is ok, 
cur idx is the ans."

trinary search?

*/