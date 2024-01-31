// BISMILLAH

// Problem link: https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        int a[26] = {0};
        for (auto c : s) {
            a[c-'a']++;
        }

        for (auto c : t) {
            a[c-'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (a[i] != 0) return false;
        }

        return true;

    }
};

signed main() {
    //
}

/*

Freq Array

*/