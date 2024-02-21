// BISMILLAH

// Problem link: https://leetcode.com/problems/surrounded-regions/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    bool vis[201][201];
    void solve(std::vector<std::vector<char>>& board) {
        int N = (int)board.size();
        int M = (int)board[0].size();
        std::function<void(int,int)> dfs = [&] (int x, int y) {
            if (std::min(x,y)<0 || x == N || y == M) {
                return;
            }
            if (board[x][y] == 'X') {
                return;
            }
            if (vis[x][y]) {
                return;
            }
            vis[x][y] = 1;
            dfs(x+1,y);
            dfs(x-1,y);
            dfs(x,y+1);
            dfs(x,y-1);
        };
        for (int i = 0; i < N; i++) {
            if (board[i][0] == 'O') {
                dfs(i,0);
            }
            if (board[i][M-1] == 'O') {
                dfs(i,M-1);
            }
        }
        for (int j = 0; j < M; j++) {
            if (board[0][j] == 'O') {
                dfs(0,j);
            }
            if (board[N-1][j] == 'O') {
                dfs(N-1,j);
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

signed main() {
    //
}

/*

dfs, flood fill from border of the grid

*/