// BISMILLAH

// Problem link: https://leetcode.com/problems/add-binary/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int c = 0;
        std::string ans;
        int fi, se; fi = se = 0;
        while (fi < (int)a.size() && se < (int)b.size()) {
            int v = c+(a[fi++]-'0')+(b[se++]-'0');
            int r = v%2;
            ans += r+'0';
            c = v/2;
        }
        while (fi < (int)a.size()) {
            int v = c+(a[fi++]-'0');
            int r = v%2;
            ans += r+'0';
            c = v/2;
        }
        while (se < (int)b.size()) {
            int v = c+(b[se++]-'0');
            int r = v%2;
            ans += r+'0';
            c = v/2;
        }
        if (c) ans += c+'0';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

signed main() {
    //
}

/*

string sum

*/