// BISMILLAH

// Problem link: https://leetcode.com/problems/word-search/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int N, M;
    bool vis[10][10];
    std::vector<std::vector<char>> b;
    std::string w;

    bool fn(int r, int c, int at) {
        if (at == (int)w.size()) return 1;  // found
        if (std::min(r,c) < 0 || r == M || c == N) return 0;
        if (w[at] != b[r][c]) return 0;
        if (vis[r][c]) return 0;
        vis[r][c] = 1;

        bool local = 0;
        local |= fn(r+1, c, at+1);
        local |= fn(r-1, c, at+1);
        local |= fn(r, c+1, at+1);
        local |= fn(r, c-1, at+1);

        vis[r][c] = 0;

        return local;

    }

    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        bool ans = 0;
        b = board;
        w = word;
        M = (int)board.size();
        N = (int)board[0].size();
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) {
            if (board[i][j] == word[0]) {
                ans |= fn(i, j, 0);
            }
        }
        return ans;
    }
};

signed main() {
    //
}

/*

recursion, word size recursion stack, tried pruning

*/