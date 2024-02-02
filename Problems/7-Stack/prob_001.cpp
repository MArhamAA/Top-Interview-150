// BISMILLAH

// Problem link: https://leetcode.com/problems/valid-parentheses/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    bool isValid(std::string s) {
        std::vector<char> st;
        bool OK = 1;

        for (auto c : s) {
            if (st.empty()) {
                st.push_back(c);
            } else {
                switch(c) {
                    case '(':
                    case '{':
                    case '[':
                        st.push_back(c);
                        break;
                    case ')':
                        if (st.empty() || st.back() != '(') {
                            OK = 0;
                            break;
                        } else {
                            st.pop_back();
                        }
                        break;
                    case '}':
                        if (st.empty() || st.back() != '{') {
                            OK = 0;
                            break;
                        } else {
                            st.pop_back();
                        }
                        break;
                    case ']':
                        if (st.empty() || st.back() != '[') {
                            OK = 0;
                            break;
                        } else {
                            st.pop_back();
                        }
                        break;
                }
            }
        }

        return OK && st.empty();

    }
};

signed main() {
    //
}

/*

valid parentheses using stack

*/