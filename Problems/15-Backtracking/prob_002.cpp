// BISMILLAH

// Problem link: https://leetcode.com/problems/combinations/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::vector<int> cur;
    void fn(int n, int k, std::vector<std::vector<int>> &a) {
        if (k == 0) {
            a.push_back(cur);
            return;
        }
        int st = cur.size() ? cur.back()+1 : 1;
        for (int i = st; i <= n; i++) {
            cur.push_back(i);
            fn(n, k-1, a);
            cur.pop_back();
        }
    }

    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> ans;
        fn(n,k,ans);
        return ans;
    }
};

signed main() {
    //
}

/*

backtrack, recursion, combination

*/