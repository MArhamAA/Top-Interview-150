// BISMILLAH

// Problem link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string,int> count, ini;
        for (auto i : words) ini[i]++;

        int len = (int)words.size()*words[0].size(), each = (int)words[0].size();
        vector<string> window;
        for (int i = 0; i < len; i += each) {
            string ss;
            for (int j = i, c = 0; c < each; c++, j++) {
                ss += s[j];
            }
            window.push_back(ss);
        }
        for (auto i : window) count[i]++;

        bool ok = 1;
        for (auto i : count) {
            if (ini[i.first] != i.second) ok = 0;
        }
        if (ok) ans.push_back(0);

        for (int i = len; i < s.size(); i++) {
            int j = i-len;
            ok = 1;
            count.clear();
            int new_char = j + each;

            for (auto &w : window) {
                w.erase(w.begin());
                w += s[new_char];
                new_char += each;
            }

            // for (auto w : window) cout << w << " "; cout << endl;

            for (auto w : window) {
                count[w]++;
            }

            for (auto u : count) {
                if (ini[u.first] != u.second) ok = 0;
            }

            if (ok) ans.push_back(j+1);
        }
        return ans;
    }
};

signed main() {
    //
}

/*

bruteforce, window, entry/end in segment
heavy complexity

*/