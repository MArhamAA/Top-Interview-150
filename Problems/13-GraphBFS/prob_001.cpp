// BISMILLAH

// Problem link: https://leetcode.com/problems/snakes-and-ladders/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

using pii = std::pair<int,int>;
const int inf = 1<<20;
class Solution {
public:
    int cost[500];
    int snakesAndLadders(std::vector<std::vector<int>>& board) {
        int N = (int) board.size();
        std::queue<int> q;
        q.push(1);
        for (int i = 2; i <= N*N; i++) {
            cost[i] = inf;
        }
        int ans = -1;
        while ((int)q.size()) {
            int box = q.front();
            int cur_cost = cost[box];
            q.pop();
            if (box == N*N) {
                ans = cur_cost;
                break;
            }
            for (int d = 1; d <= 6 && box+d <= N*N; d++) {
                int next_box = d+box;
                int row = (next_box+N-1)/N;
                row = N-row+1;
                int col = next_box%N;
                if (col == 0) col = N;
                if (N&1 && row%2==0) {
                    col = N-col+1;
                }
                if (N%2==0 && row&1) {
                    col = N-col+1;
                }
                if (board[row-1][col-1] != -1) {
                    next_box = board[row-1][col-1];
                }
                if (cost[next_box] > cur_cost + 1) {
                    cost[next_box] = cur_cost+1;
                    q.push(next_box);
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

bfs

*/