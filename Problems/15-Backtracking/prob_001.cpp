// BISMILLAH

// Problem link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::vector<std::string> com;

    void fn(std::string s, int at, std::string mp, std::vector<std::string> &a) {
        if (at == (int)s.size()) {
            if ((int)s.size()) a.push_back(mp);
            return;
        }
        for (auto c : com[s[at]-'0']) {
            mp += c;
            fn(s, at+1, mp, a);
            mp.pop_back();
        }
    }

    std::vector<std::string> letterCombinations(std::string digits) {
        char lst = 'a';
        com.resize(10);
        for (char i = '2'; i <= '9'; i++) {
            int at = i-'0';
            int c = 3;
            while (c--) {
                com[at].push_back(lst++);
            }
            if (at == 7 || at == 9) com[at].push_back(lst++);
        }
        std::vector<std::string> ans;
        fn(digits, 0, "", ans);
        return ans;
    }
};

signed main() {
    //
}

/*

backtrack, recursion

*/