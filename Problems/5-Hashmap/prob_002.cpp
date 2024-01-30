// BISMILLAH

// Problem link: https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        int N = (int)s.size();
        std::unordered_map<char,char> val;
        std::unordered_map<char,bool> dist;
        bool ans = 1;

        for (int i = 0; i < N; i++) {
            if (val.find(s[i]) == val.end()) {
                val[ s[i] ] = t[i];
            } else if (val[ s[i] ] != t[i]) {
                ans = 0;
            }
        }

        for (auto c : val) {
            if (dist.find(c.second) != dist.end()) {
                ans = 0;
            } dist[c.second] = 1;
        }

        return ans;
    }
};

signed main() {
    //
}

/*

Freq Array

*/