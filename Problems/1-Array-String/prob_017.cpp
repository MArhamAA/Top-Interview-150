 // BISMILLAH

#include <bits/stdc++.h>
 
int romanToInt(std::string s) {
    int i = 0, N = (int)s.size(), ans = 0;
    while (i < N) {
        if (s[i] == 'I') {
            if (i + 1 < N) {
                if (s[i+1] == 'V') {
                    ans += 4;
                    i += 2;
                } else if (s[i+1] == 'X') {
                    ans += 9;
                    i += 2;
                } else {
                    ans++;
                    i++;
                }
            } else {
                ans++;
                i++;
            }
        } else if (s[i] == 'V') {
            ans += 5;
            i++;
        } else if (s[i] == 'X') {
            if (i + 1 < N) {
                if (s[i+1] == 'L') {
                    ans += 40;
                    i += 2;
                    continue;
                } else if (s[i+1] == 'C') {
                    ans += 90;
                    i += 2;
                    continue;
                }
            }
            ans += 10;
            i++;
        } else if (s[i] == 'L') {
            ans += 50;
            i++;
        } else if (s[i] == 'C') {
            if (i + 1 < N) {
                if (s[i+1] == 'D') {
                    ans += 400;
                    i += 2;
                    continue;
                } else if (s[i+1] == 'M') {
                    ans += 900;
                    i += 2;
                    continue;
                }
            }
            ans += 100;
            i++;
        } else if (s[i] == 'D') {
            ans += 500;
            i++;
        } else {
            ans += 1000;
            i++;
        }
    }

    return ans;
}

signed main() {
	//
}

/*

https://leetcode.com/problems/roman-to-integer/description/?envType=study-plan-v2&envId=top-interview-150

Implementation

*/