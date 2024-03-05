// BISMILLAH

// Problem link: https://leetcode.com/problems/palindrome-number/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return 0;
        if (x == 0) return 1;

        std::vector<int> a;
        while (x) {
            a.push_back(x%10);
            x /= 10;
        }
        for (int i = 0; i < (int)a.size()/2; i++) {
            if (a[i] != a[(int)a.size()-i-1]) return 0;
        }

        return 1;
    }
};

signed main() {
    //
}

/*

palindrome check

*/