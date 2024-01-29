// BISMILLAH

// Problem link: https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        int a[26] = {0}, b[26] = {0};
        for (char c : ransomNote) a[c-'a']++;
        for (char c : magazine) b[c-'a']++;

        for (int i = 0; i < 26; i++) {
            if (a[i] > b[i]) {
                return false;
            }
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