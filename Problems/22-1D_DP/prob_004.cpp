// BISMILLAH

// Problem link: https://leetcode.com/problems/word-break/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    unordered_map<string, bool> dp;
    int N;
    string req;
    vector<string> w;
    bool prefixCheck(string a) {
        for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] != req[i]) return 0;
        }
        return 1;
    }
    bool fn(string cur) {
        if ((int)cur.size() > (int)req.size()) return 0;
        if (cur == req) return 1;
        if (prefixCheck(cur) == 0) return 0;
        if (dp.find(cur) != dp.end()) return dp[cur];

        bool local = 0;
        for (int i = 0; i < N; i++) {
            local |= fn(cur+w[i]);
        }
        return dp[cur] = local;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        req = s;
        N = (int)wordDict.size();
        w = wordDict;
        return fn("");
    }
};

signed main() {
    //
}

/*

recursive dp, state hashmap
pruning: size, prefixMatch

*/