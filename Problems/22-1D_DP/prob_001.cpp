// BISMILLAH

// Problem link: https://leetcode.com/problems/climbing-stairs/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int climbStairs(int n) {
        int a, b, c; a = b = 1;
        if (n == 1) return 1;
        for (int i = 2; i <= n; i++) {
            c = a+b;
            b = a;
            a = c;
        }
        return c;
    }
};

signed main() {
    //
}

/*

fibonacci number

*/