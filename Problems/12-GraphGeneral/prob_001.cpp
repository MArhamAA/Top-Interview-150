// BISMILLAH

// Problem link: https://leetcode.com/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    bool vis[500][500];
    int numIslands(std::vector<std::vector<char>>& grid) {
        int ans = 0, N = (int)grid.size(), M = (int)grid[0].size();
        std::function<void(int,int)> dfs = [&] (int x, int y) {
            if (std::min(x,y)<0 || x == N || y == M) {
                return;
            }
            if (grid[x][y] == '0') {
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
        for (int i = 0; i < (int)grid.size(); i++) {
            for (int j = 0; j < (int)grid[i].size(); j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    ans++;
                    dfs(i,j);
                }
            }
        }
        return ans;
    }
};

signed main() {
    //
}

/*

dfs

*/