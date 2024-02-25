// BISMILLAH

// Problem link: https://leetcode.com/problems/word-search-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

struct node {
    int x, y;
    string s;
    node() {}
    node (int _x, int _y, string _s) {
        x = _x;
        y = _y;
        s = _s;
    }
};

class Solution {
public:
    int T[50005][26], root, used, N, M;
    bool mark[50005], mask[12][12];
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void insert(string word) {
        int cur = root;
        for (auto i : word) {
            int n = i-'a';
            if (T[cur][n] == -1) {
                T[cur][n] = ++used;
            }
            cur = T[cur][n];
        }
        mark[cur] = 1;
    }
    
    int search(string word) {
        int cur = root;
        for (auto i : word) {
            int n = i-'a';
            if (T[cur][n] == -1) {
                return -1;
            }
            cur = T[cur][n];
        }
        return mark[cur];
    }

    void fn(int x, int y, string s, vector<vector<char>> &b, set<string> &a) {
        if (min(x, y) < 0 || x == N || y == M) return;
        if (mask[x][y]) return;
        s += b[x][y];
        mask[x][y] = 1;

        int out = search(s);
        if (out == -1) {
            mask[x][y] = 0;
            s.pop_back();
            return;
        }
        if (out) {
            a.insert(s);
        }

        fn(x+1, y, s, b, a);
        fn(x-1, y, s, b, a);
        fn(x, y+1, s, b, a);
        fn(x, y-1, s, b, a);
        mask[x][y] = 0;
        s.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = 0;
        memset(mark, 0, sizeof(mark));
        memset(T, -1, sizeof(T));
        used = 0;
        N = (int)board.size();
        M = (int)board[0].size();

        for (auto s : words) {
            insert(s);
        }

        vector<string> ans;
        set<string> a;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
            fn(i, j, "", board, a);
        }

        for (auto i : a) ans.push_back(i);

        return ans;
    }
};

signed main() {
    //
}

/*

Trie & Backtracking, reverse thinking

*/