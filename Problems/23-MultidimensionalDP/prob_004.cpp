// BISMILLAH

// Problem link: https://leetcode.com/problems/longest-palindromic-substring/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 1, l, r; l = r = 0;
        int N = (int)s.size();
        // dp[i][j] = 1 if [i,j] is a palindrome && i <= j, 0 otherwise
        bool dp[N][N]; memset(dp, 0, sizeof(dp));
        for (int i = 0; i < N; i++) dp[i][i] = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (s[i] == s[j]) {
                    if (j+1 <= i-1 && dp[j+1][i-1]) {
                        if (ans < i-j+1) {
                            ans = i-j+1;
                            l = j;
                            r = i;
                        }
                        dp[j][i] = 1;
                    } else if (j+1 > i-1) {
                        if (ans < 2) {
                            ans = 2;
                            l = j;
                            r = i;
                        }
                        dp[j][i] = 1;
                    }
                }
            }
        }
        return s.substr(l,r-l+1);
    }
};

signed main() {
    //
}

/*

"dp[i][j] = (i...j) is palindrome ? 1 : 0
base case, dp[i][i] = 1
then, for each ""i"" find min ""j"" where 
s[i] == s[j] and dp[j+1][i-1] = 1; (j <= i)

Another, binary search approach:
binary search on odd length substring
binary search on even length substring"

*/