// BISMILLAH

// Problem link: https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

bool isChar(char &c) {
    if (c >= '0' && c <= '9') return true;
    if (c < 'A') return false;
    if (c > 'Z' && c < 'a') return false;
    if (c > 'z') return false;
    if (c < 'a') {
        c -= 'A';
        c += 'a';
    }
    return true;
}
bool isPalindrome(std::string s) {
    int second = (int)s.size()-1;
    char first_char, second_char;
    bool ans = true;

    for (int first = 0; first < second; first++) {
        first_char = s[first];
        if (isChar(first_char)) {
            while (second > first) {
                second_char = s[second--];
                if (isChar(second_char)) {
                    if (first_char != second_char) ans = false;
                    break;
                }
            }
        } else {
            continue;
        }
    }

    return ans;
}

signed main() {
    //
}

/*

Implementation

*/