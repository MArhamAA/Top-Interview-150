// BISMILLAH

// Problem link: https://leetcode.com/problems/game-of-life/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        // replace changalbe 0 -> 2, changable 1 -> 3
        int N = (int)board.size();
        int M = (int)board[0].size();

        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        auto OK = [&] (int x, int y) {
            return std::min(x,y)>=0 && x < N && y < M;
        };

        int live_N;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 0) {
                    live_N = 0;
                    for (int d = 0; d < 8; d++) {
                        int new_i = i+dx[d];
                        int new_j = j+dy[d];
                        if (OK(new_i, new_j)) {
                            if (board[new_i][new_j] == 1 || board[new_i][new_j] == 3) {
                                live_N++;
                            }
                        }
                    }
                    if (live_N == 3) {
                        board[i][j] = 2;
                    }
                } else {
                    live_N = 0;
                    for (int d = 0; d < 8; d++) {
                        int new_i = i+dx[d];
                        int new_j = j+dy[d];
                        if (OK(new_i, new_j)) {
                            if (board[new_i][new_j] == 1 || board[new_i][new_j] == 3) {
                                live_N++;
                            }
                        }
                    }
                    if (live_N < 2 || live_N > 3) {
                        board[i][j] = 3;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                } else if (board[i][j] == 3) {
                    board[i][j] = 0;
                }
            }
        }

    }
};

signed main() {
    //
}

/*

Implementation, observation
in-place

*/