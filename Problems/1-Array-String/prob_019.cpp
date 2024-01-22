 // BISMILLAH

#include <bits/stdc++.h>

int lengthOfLastWord(std::string s) {
        int ans = 0;
        std::stringstream ss(s);
        while (ss >> s) {
            ans = (int)s.size();
        }

        return ans;
    }

signed main() {
	//
}

/*

https://leetcode.com/problems/length-of-last-word/description/?envType=study-plan-v2&envId=top-interview-150

Implementation

*/