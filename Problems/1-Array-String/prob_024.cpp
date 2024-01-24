// BISMILLAH

#include "bits/stdc++.h"

std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
    int N = (int)words.size();
    std::vector<std::string> ans;

    std::string s, cur;
    int tot, len, idx = 0, roiche, div, start;

    while (idx < N) {
        tot = 1;
        start = idx;
        len = (int)words[idx++].size();

        while (idx < N) {
            cur = words[idx];
            if (len+1 + (int)cur.size() <= maxWidth) {
                tot++;
                len += (int)cur.size()+1;
            } else {
                break;
            }
            idx++;
        }

        roiche = maxWidth-len;
        if (idx == N) {
            // last line
            s = words[start++];
            while (start < idx) {
                s += ' ';
                s += words[start++];
            }
            s += std::string(roiche,' ');

        } else {
            if (tot > 1) {
                div = roiche/(tot-1);
                roiche %= (tot-1);
            }

            s = words[start++];
            while (start < idx) {
                s += ' ';
                s += std::string(div,' ');
                if (roiche) {
                    s += ' ';
                    roiche--;
                }
                s += words[start++];
            }
            s += std::string(roiche,' ');
        }
        ans.push_back(s);
    }

    return ans;
}

signed main() {
    //
}

/*

https://leetcode.com/problems/text-justification/description/?envType=study-plan-v2&envId=top-interview-150

Implementation, string

*/