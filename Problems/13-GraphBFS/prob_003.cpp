// BISMILLAH

// Problem link: https://leetcode.com/problems/word-ladder/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> list;
        for (auto i : wordList) list[i] = 1;
        queue<string> q; q.push(beginWord);
        unordered_map<string, int> cost; cost[beginWord] = 1;
        int ans = 0;
        while ((int)q.size()) {
            string s = q.front();
            q.pop();
            int cur_cost = cost[s];
            if (s == endWord) {
                ans = cur_cost;
                break;
            }
            for (auto &i : s) {
                char ini = i;
                for (char c = 'a'; c <= 'z'; c++) {
                    i = c;
                    if (list.find(s) != list.end()) {
                        if (cost.find(s) == cost.end() || cost[s] > cur_cost+1) {
                            cost[s] = cur_cost+1;
                            q.push(s);
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

bfs, shortes path

*/