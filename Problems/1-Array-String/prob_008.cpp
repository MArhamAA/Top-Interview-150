// BISMILLAH

#include "bits/stdc++.h"

int maxProfit(std::vector<int>& prices) {
    int N = (int)prices.size();
    int ans = 0, so_far_small = -1;
    for (int i = 0; i < N; i++) {
        int cur = prices[i];
        if (so_far_small != -1 && cur > so_far_small) {
            ans += (cur - so_far_small);
        }
        so_far_small = cur;
    }

    return ans;
}

signed main() {
    //
}

/*

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/?envType=study-plan-v2&envId=top-interview-150

Observation, Greedy

*/