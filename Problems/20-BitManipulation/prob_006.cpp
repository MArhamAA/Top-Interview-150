// BISMILLAH

// Problem link: https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // 2th power
        int left_last_bit=0;
        for (int i = 30; i >= 0; i--) {
            if (left & (1<<i)) {
                left_last_bit = i;
                break;
            }
        }
        int right_last_bit=0;
        for (int i = 30; i >= 0; i--) {
            if (right & (1<<i)) {
                right_last_bit = i;
                break;
            }
        }
        if (left_last_bit != right_last_bit) return 0;

        int ans = 0;
        for (int i = right_last_bit; i >= 0; i--) {
            bool fi = left&(1<<i) ? 1 : 0;
            bool se = right&(1<<i) ? 1 : 0;
            if (fi&&se) ans += 1<<i;
            else if (fi != se) break;
        }
        return ans;
    }
};

signed main() {
    //
}

/*

"2th power, continuous 2th pow range 
same bit, observe bit pattern"

*/