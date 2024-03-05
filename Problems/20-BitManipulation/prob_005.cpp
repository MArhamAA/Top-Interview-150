// BISMILLAH

// Problem link: https://leetcode.com/problems/single-number-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ans = 0, bit_count;
        for (int bit = 0; bit < 32; bit++) {
            bit_count = 0;
            for (int &i : nums) {
                if ((1LL<<bit) & i) bit_count++;
            }    
            bit_count %= 3;
            if (bit_count) ans += 1<<bit;
        }
        return ans;
    }
};

signed main() {
    //
}

/*

"1' bit_count for each bit position, 
then mod%3 concept"
"O(1) extra space
O(N) time"

*/