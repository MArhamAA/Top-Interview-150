// BISMILLAH

// Problem link: https://leetcode.com/problems/minimum-genetic-mutation/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

using pii = std::pair<int,int>;
const int inf = 1<<20;

class Solution {
public:
    int minMutation(std::string startGene, std::string endGene, std::vector<std::string>& bank) {
        std::unordered_map<std::string, bool> B;
        for (auto i : bank) {
            B[i] = 1;
        }
        std::queue<std::string> q;
        q.push(startGene);
        std::unordered_map<std::string,int> cost;
        cost[startGene] = 0;
        int ans = -1;
        std::vector<char> val = {'A', 'C', 'G', 'T'};

        while ((int)q.size()) {
            std::string s = q.front();
            q.pop();
            int cur_cost = cost[s];
            if (s == endGene) {
                ans = cur_cost;
                break;
            }
            for (auto &i : s) {
                char ini = i;
                for (int at = 0; at < 4; at++) {
                    i = val[at];
                    if (B.find(s) != B.end()) {
                        if (cost.find(s) == cost.end() || cost[s] > cur_cost+1) {
                            q.push(s);
                            cost[s] = cur_cost+1;
                        }
                    }
                }
                i = ini;
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