// BISMILLAH

#include <bits/stdc++.h>

std::string reverseWords(std::string s) {
    int N = (int)s.size(), count = 0, started = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] != ' ') {
            started = 1;
            count = 0;
        } else {
            if (started) {
                if (count) {
                    count = 0;
                    for (int j = i; j; j--) {
                        std::swap(s[j-1], s[j]);
                    }
                }
                count++;
            }
        }
    }
    while (true) {
        if (s[0] != ' ') break;
        s.erase(s.begin());
        N--;
    }
    while (s.back() == ' ') {
        N--;
        s.pop_back();
    }
    std::reverse(s.begin(), s.end());
    s += ' ';  // N++
    
    started = -1;
    for (int i = 0; i <= N; i++) {
        if (s[i] == ' ') {
            int len = i-started;
            for (int j = 0; j < len/2; j++) {
                std::swap(s[j+started], s[started+len-j-1]);
            }
            started = -1;
        } else {
            if (started == -1) started = i;
        }
    }

    s.pop_back();
    return s;
}

signed main() {
	//
}

/*

https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

Implementation, string

O(1) space, O(N*N) time

*/