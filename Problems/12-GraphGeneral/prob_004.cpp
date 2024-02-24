// BISMILLAH

// Problem link: https://leetcode.com/problems/evaluate-division/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

struct node{
    string v;
    double w;
    node (string _v, double _w) {
        v = _v;
        w = _w;
    }
};

class Solution {
public:
    unordered_map<string, vector<node>> g;
    unordered_map<string, bool> vis;

    void dfs(string u, string f, double cur, double &val) {
        if (vis[u]) return;
        vis[u] = 1;
        if (u == f && (int)g[u].size()) {
            val = cur;
            return;
        }
        for (auto N : g[u]) {
            dfs(N.v, f, cur*N.w, val);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int at = 0;
        for (auto ab : equations) {
            double val = values[at++];
            string a = ab[0];
            string b = ab[1];
            node v = node(b, val);
            g[a].push_back(v);
            v = node(a, 1/val);
            g[b].push_back(v);
        }

        vector<double> ans;
        for (auto q: queries) {
            string a = q[0];
            string b = q[1];
            double val = -1;
            dfs(a, b, 1, val);
            ans.push_back(val);
            vis.clear();
        }

        return ans;
    }
};

signed main() {
    //
}

/*

graph traversal: bfs/dfs, hashmap

*/