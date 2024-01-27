// BISMILLAH

// Problem link: https://leetcode.com/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

std::string minWindow(std::string s, std::string t) {
    int N = (int)s.size();
    std::unordered_map<char,int> ini, window;
    std::vector<char> list;
    for (char c = 'a'; c <= 'z'; c++) {
        list.push_back(c);
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        list.push_back(c);
    }
    for (char c : t) ini[c]++;
    int first = 0;

    auto OK = [&] () {
        for (auto c : list) {
            if (window[c] < ini[c]) {
                return false;
            }
        }
        return true;
    };

    int found, siz = N, L=-1, R;
    for (int second = 0; second < N; second++) {
        window[s[second]]++;
        found = 0;
        if (OK()) {
            while (true) {
                found = 1;
                window[s[first]]--;
                first++;
                if (window[s[first-1]] < ini[s[first-1]]) break;
            }
        }
        if (found) {
            if (siz > second-first+1) {
                siz = second-first+1;
                L = first-1; R = second;
            }
        }
    }

    std::string ans;
    if (L != -1) {
        for (int i = L; i <= R; i++) ans += s[i];
    }

    return ans;
}

signed main() {
    //
}

/*

Maintain a window, Freq array

O(42 N) time

*/