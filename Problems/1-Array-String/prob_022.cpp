// BISMILLAH

#include "bits/stdc++.h"

std::string convert(std::string s, int numRows) {
    if (numRows == 1) return s;

    int N = (int)s.size(), M = 0, val = 0, turn = 1;
    while (val < N) {
        if (turn) {
            val += numRows;
            M++;
        } else {
            val += numRows-2;
            M += numRows-2;
        }
        turn ^= 1;
    } M++;
    char a[numRows][M];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] = '#';
        }
    }
    int idx = 0, col = 0; turn = 1;
    while (col < M && idx < N) {
        if (turn) {
            for (int i = 0; i < numRows && idx < N; i++) {
                a[i][col] = s[idx++];
            }
            col++;
        } else {
            for (int c = 0, i = numRows-2; c < numRows-2 && idx < N; i--, c++, col++) {
                a[i][col] = s[idx++];
            }
        }
        turn ^= 1;
    }

    std::string ans;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] != '#') ans += a[i][j];
        }
    }

    return ans;
}

signed main() {
    //
}

/*

https://leetcode.com/problems/zigzag-conversion/?envType=study-plan-v2&envId=top-interview-150

Implementation, string

*/