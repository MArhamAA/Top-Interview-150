// BISMILLAH

// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int N;
    vector<int> p;
    int dp[100005][3][2];

    int fn(int at, int trans_no, bool ok) {  // ok = 1 if lastly do buy
        if (trans_no == 2) return 0;
        if (at == N) return 0;

        if (dp[at][trans_no][ok] != -1) return dp[at][trans_no][ok];
        
        int ans = fn(at+1, trans_no, ok);
        if (ok) {
            ans = max(ans, fn(at+1, trans_no+1, 0)+p[at]);
        } else {
            ans = max(ans, fn(at+1, trans_no, 1)-p[at]);
        }
        return dp[at][trans_no][ok] = ans;
    }
    int maxProfit(vector<int>& prices) {
        N = (int)prices.size();
        p = prices;
        memset(dp,-1,sizeof(dp));
        return fn(0,0,0);
    }
};

signed main() {
    //
}

/*

observation

"resource_link_to_learn
https://hashnode.com/post/best-time-to-buy-and-sell-stocks-a-comprehensive-guide-cko8xg43m0oz194s114kz71pn"

*/