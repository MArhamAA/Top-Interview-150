// BISMILLAH

// Problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

int lengthOfLongestSubstring(std::string s) {
    int ans = 0;
    std::unordered_map<char,int> freq;
    char cur;
    int N = (int)s.size(), first = 0;
    for (int second = 0; second < N; second++) {
        cur = s[second];
        freq[cur]++;
        if (freq[cur] == 1) {
            //
        } else {
            ans = std::max(ans, second-first);
            while (freq[cur] > 1) {
                freq[s[first]]--;
                first++;
            }
        }
    }

    ans = std::max(ans, N-first);

    return ans;
}

signed main() {
    //
}

/*

Maintain a window, Freq array

*/