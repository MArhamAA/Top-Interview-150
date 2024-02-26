// BISMILLAH

// Problem link: https://leetcode.com/problems/combination-sum/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::vector<int> cur;

    void fn(int at, std::vector<int>& a, std::vector<std::vector<int>>& b, int sum, int T) {
        if (sum > T) return;
        if (sum == T) {
            b.push_back(cur);
            return;
        }
        if (at == (int)a.size()) return;
        
        fn(at+1, a, b, sum, T);

        cur.push_back(a[at]);
        fn(at,a,b,sum+a[at],T);
        cur.pop_back();
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ans;
        fn(0, candidates, ans, 0, target);
        return ans;
    }
};

signed main() {
    //
}

/*

backtrack, coinChange variation

*/