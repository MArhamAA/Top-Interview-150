// BISMILLAH

// Problem link: https://leetcode.com/problems/number-of-1-bits/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int tot = 0;
        for (int i = 0; i < 32; i++) {
            if ((1ULL<<i)&n) tot++;
        }
        return tot;
    }
};

signed main() {
    //
}

/*

binary bits

*/