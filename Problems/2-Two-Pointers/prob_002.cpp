// BISMILLAH

// Problem link: https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

bool isSubsequence(std::string s, std::string t) {
    int N = (int)s.size(), M = (int)t.size(), idx = 0;
    for (int i = 0; i < M && idx < N; i++) {
        if (s[idx] == t[i]) {
            idx++;
        }
    }

    return idx==N;
}

signed main() {
    //
}

/*

Implementation

*/