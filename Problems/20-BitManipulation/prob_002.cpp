// BISMILLAH

// Problem link: https://leetcode.com/problems/reverse-bits/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            if (n&(1<<i)) {
                uint32_t cur = 32-i-1;
                ans += 1ULL<<cur;
            }
        }
        return ans;
    }
};

signed main() {
    //
}

/*

binary bits

*/