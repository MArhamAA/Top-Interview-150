// BISMILLAH

// Problem link: https://leetcode.com/problems/powx-n/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    double binpow(double x, int n) {
        if (n == 0) return 1;
        double res = binpow(x,n/2);
        res *= res;
        if (n&1) res *= x;
        return res;
    }
    double myPow(double x, int n) {
        bool neg = n < 0;
        n = abs(n);
        double ans = binpow(x,n);
        if (neg) ans = 1/ans;
        return ans;
    }
};

signed main() {
    //
}

/*

binary exponentiation

*/