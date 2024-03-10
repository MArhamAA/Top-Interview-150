// BISMILLAH

// Problem link: https://leetcode.com/problems/interleaving-string/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

using psi = pair<string,int>;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int N = (int)s1.size();
        int M = (int)s2.size();
        auto check = [&] (string s) {
            for (int i = 0; i < (int)s.size(); i++) {
                if (s3[i] != s[i]) return 0;
            }
            return 1;
        };
        vector<vector<vector<unordered_map<string,bool>>>> dp(N+1, vector<vector<unordered_map<string,bool>>> (M+1, vector<unordered_map<string,bool>>(3)));
        function<bool(string, int, int, int)> fn = [&] (string s, int fi, int se, int sta) {
            if ((int)s.size() > (int)s3.size()) return false;
            if (check(s) == 0) return false;
            if (fi == N && se == M) return s==s3;
            if (dp[fi][se][sta].find(s) != dp[fi][se][sta].end()) return dp[fi][se][sta][s];

            bool local = 0;
            if (sta == 0) {
                for (int i = fi; i < N; i++) {
                    local |= fn(s+s1.substr(fi,i-fi+1),i+1,se,1);
                }
                for (int i = se; i < M; i++) {
                    local |= fn(s+s2.substr(se,i-se+1),fi,i+1,0);
                }
            } else if (sta == 1) {
                for (int i = se; i < M; i++) {
                    local |= fn(s+s2.substr(se,i-se+1),fi,i+1,0);
                }
            } else {
                for (int i = fi; i < N; i++) {
                    local |= fn(s+s1.substr(fi,i-fi+1),i+1,se,1);
                }
            }
            return dp[fi][se][sta][s]= local;
        };
        return fn("",0,0,0);
    }
};

signed main() {
    //
}

/*

recursion, memoization

*/