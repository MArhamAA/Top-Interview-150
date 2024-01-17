// BISMILLAH

#include <bits/stdc++.h>

int hIndex(std::vector<int>& citations) {
    int count[1001] = {0};
    for (auto i : citations) {
        count[i]++;
    }

    int ans, TOT = 0;
    for (int i = 1000; i >= 0; i--) {
        TOT += count[i];
        if (TOT >= i) {
            ans = i;
            break;
        }
    }

    return ans;
}

signed main() {
	//
}

/*

https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150

Prefix sum and frequency count.

*/