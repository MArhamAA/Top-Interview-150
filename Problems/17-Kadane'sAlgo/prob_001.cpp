// BISMILLAH

// Problem link: https://leetcode.com/problems/maximum-subarray/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int fn(int l, int r, std::vector<int>& a) {
        if (l > r) return INT_MIN;
        if (l == r) return a[l];
        int m = l+(r-l)/2;
        int L = fn(l, m-1, a);
        int R = fn(m+1, r, a);
        // ignore middle element
        int local = std::max(L, R);
        
        // include middle element
        int sum = 0, l_sub = INT_MIN, r_sub = INT_MIN;
        for (int i = m; i >= l; i--) {
            sum += a[i];
            l_sub = std::max(l_sub, sum);
        }
        sum = 0;
        for (int i = m; i <= r; i++) {
            sum += a[i];
            r_sub = std::max(r_sub, sum);
        }

        int sub = std::max({l_sub, r_sub, l_sub+r_sub-a[m]});
        return std::max(local, sub);
    }

    int maxSubArray(std::vector<int>& nums) {
        int N = (int)nums.size();
        return fn(0, N-1, nums);
    }
};

signed main() {
    //
}

/*

divide and conquer: ignore mid, with mid
O(N lg N) D&C

*/