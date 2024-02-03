// BISMILLAH

// Problem link: https://leetcode.com/problems/simplify-path/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::string ans;
        int N = (int)path.size();
        std::vector<std::string> st;

        std::string cur;

        for (auto c : path) {
            if (c == '/') {
                if (cur == "..") {
                    if ((int)st.size()) st.pop_back();
                } else if (cur == ".") {
                    //
                }
                else if (cur != "") {
                    st.push_back(cur);
                }
                cur = "";
            } else {
                cur += c;
            }
        }
        if (cur == "..") {
            if ((int)st.size()) st.pop_back();
        }
        else if (cur != "" && cur != ".") st.push_back(cur);

        ans += "/";
        N = (int)st.size();

        for (int i = 0; i < N; i++) {
            ans += st[i];
            ans += "/";
        }

        if ((int)ans.size()>1) ans.pop_back();

        return ans;
    }
};

signed main() {
    //
}

/*

LIFO, implementation

*/