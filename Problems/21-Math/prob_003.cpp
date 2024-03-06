// BISMILLAH

// Problem link: https://leetcode.com/problems/factorial-trailing-zeroes/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for (int i = 5; i <= n; i *= 5) {
            ans += n/i;
        }

        return ans;
    }
};

signed main() {
    //
}

/*

2*5 produces new zero
O(N log N) time

*/