// BISMILLAH

// Problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int N = (int)nums.size()-1;
        if (N == 0) {
            return nums[0] == target ? 0 : -1;
        }
        int lo, hi, mi, ans=-1;
        if (nums[0] < nums[N]) {
            // normal sorted array
            lo = 0, hi = N;
            while (lo <= hi) {
                mi = lo+(hi-lo)/2;
                if (nums[mi] == target) {
                    ans = mi;
                    break;
                }
                if (nums[mi] < target) {
                    lo = mi+1;
                } else {
                    hi = mi-1;
                }
            }
        } else {
            // exploring right part
            lo = 1, hi = N;
            while (lo <= hi) {
                mi = lo+(hi-lo)/2;
                if (nums[mi] == target) {
                    ans = mi;
                    break;
                }
                if (nums[mi] < target || nums[mi] > nums[N]) {
                    lo = mi+1;
                } else {
                    hi = mi-1;
                }
            }

            // exploring left part
            lo = 0, hi = N-1;
            while (lo <= hi) {
                mi = lo+(hi-lo)/2;
                if (nums[mi] == target) {
                    ans = mi;
                    break;
                }
                if (nums[mi] > target || nums[mi] < nums[0]) {
                    hi = mi-1;
                } else {
                    lo = mi+1;
                }
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