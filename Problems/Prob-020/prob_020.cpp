// BISMILLAH

#include <bits/stdc++.h>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string ans = strs[0];
    for (auto s : strs) {
        int i = 0, j = 0, N = (int)ans.size(), M = (int)s.size();
        while (i < N && j < M) {
            if (ans[i] != s[j]) {
                break;
            } i++, j++;
        }
        while (N > i) {
            ans.pop_back();
            N--;
        }
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