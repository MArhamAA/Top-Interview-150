// BISMILLAH

// Problem link: https://leetcode.com/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    void fn(int at, std::string s, int open, int close, int n, std::vector<std::string>& a) {
        if (at == 2*n) {
            if (open == close) a.push_back(s);
            return;
        }
        if (open < n) fn(at+1, s+"(", open+1, close, n, a);
        if (close < open) fn(at+1, s+")", open, close+1, n, a);
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ans;
        fn(0, "", 0, 0, n, ans);
        return ans;
    }
};

signed main() {
    //
}

/*

recursion, tried pruning

*/