// BISMILLAH

// Problem link: https://leetcode.com/problems/n-queens-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    bool col[9], d1[9][9], d2[9][9];

    int fn(int r, int n) {
        if (r == n) {
            return 1;
        }

        bool fi, se;
        int rr, cc, local = 0;

        for (int i = 0; i < n; i++) {
            if (col[i] == 0) {
                fi = se = true;
                
                rr = r, cc = i;
                while (std::min(rr,cc) >= 0) {
                    if (d1[rr][cc]) {
                        fi = false;
                        break;
                    }
                    rr--;
                    cc--;
                }

                rr = r, cc = i;
                while (rr >= 0 && cc < n) {
                    if (d2[rr][cc]) {
                        se = false;
                        break;
                    }
                    rr--;
                    cc++;
                }

                if (fi && se) {
                    d1[r][i] = d2[r][i] = col[i] = 1;
                    local += fn(r+1, n);
                    d1[r][i] = d2[r][i] = col[i] = 0;
                }
            }
        }
        return local;
    }

    int totalNQueens(int n) {
        return fn(0, n);
    }
};

signed main() {
    //
}

/*

N-Queen, backtracking

*/