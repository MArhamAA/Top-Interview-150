// BISMILLAH

// Problem link: https://leetcode.com/problems/happy-number/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    bool isHappy(int n) {
        for (int i = 0; i < 100 && n != 1; i++) {
            int sum = 0;
            while (n) {
                int rem = n%10;
                sum += rem*rem;
                n /= 10;
            }
            n = sum;
        }

        return n==1;
    }
};

signed main() {
    //
}

/*

BruteForce

*/