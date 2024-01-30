// BISMILLAH

// Problem link: https://leetcode.com/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        int N = (int)pattern.size();
        std::stringstream ss(s);
        std::unordered_map<char, std::string> pat;
        std::unordered_map<std::string, bool> dist;

        int idx = 0;
        bool ans = 1;
        while (ss >> s) {
            if (idx == N) {
                ans = 0;
                break;
            }
            if (pat.find(pattern[idx]) == pat.end()) {
                pat[ pattern[idx] ] = s;
            } else if (pat[ pattern[idx] ] != s) {
                ans = 0;
            }
            idx++;
        }

        if (idx < N) ans = 0;

        for (auto i : pat) {
            if (dist.find(i.second) == dist.end()) {
                dist[i.second] = 1;
            } else {
                ans = 0;
            }
            dist[i.second] = 1;
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