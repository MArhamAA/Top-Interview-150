// BISMILLAH

// Problem link: https://leetcode.com/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int c = 1;
        std::vector<int> ans;
        for (int i = (int)digits.size()-1; i >= 0; i--) {
            int d = digits[i];
            int s = d+c;
            ans.push_back(s%10);
            c = s/10;
        }
        while (c) {
            ans.push_back(c%10);
            c /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

signed main() {
    //
}

/*

basic addition property

*/