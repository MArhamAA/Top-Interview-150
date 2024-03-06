// BISMILLAH

// Problem link: https://leetcode.com/problems/sqrtx/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        while (1) {
            if ((long long)(ans+1)*(ans+1) <= x) ans++;
            else break;
        }
        return ans;
    }
};

signed main() {
    //
}

/*

bruteforce

*/