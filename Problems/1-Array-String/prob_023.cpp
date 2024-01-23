// BISMILLAH

#include "bits/stdc++.h"

int strStr(std::string haystack, std::string needle) {
    int N = (int)haystack.size(), M = (int)needle.size(), pos = -1;
    for (int i = 0; i < N; i++) {
        int j = 0, ii = i;
        while (ii < N && j < M) {
            if (haystack[ii] != needle[j]) {
                break;
            }
            ii++, j++;
        }
        if (j == M) {
            pos = i;
            break;
        }
    }
    return pos;
}

signed main() {
    //
}

/*

https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

Implementation, string, time O(N*N)

for time O(N) use string algos like, KMP, z-function or hashing

*/