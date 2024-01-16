// BISMILLAH

#include <bits/stdc++.h>

int maxProfit(std::vector<int>& prices) {
    int ans = 0;
    int best = prices.back();
    for (int cur, i = (int)prices.size()-2; i >= 0; i--) {
        cur = prices[i];
        ans = std::max(ans, best-cur);
        best = std::max(best,cur);
    }

    return ans;
}


signed main() {
	//
}

/*

https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150

Iteration from the end

O(N) time

*/