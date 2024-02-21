// BISMILLAH

// Problem link: https://leetcode.com/problems/course-schedule-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::vector<int> g[2001];
    int inD[2001];
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        for (auto i : prerequisites) {
            int u = i[0];
            int v = i[1];
            inD[u]++;
            g[v].push_back(u);
        }
        // toposort
        std::queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inD[i] == 0) {
                q.push(i);
            }
        }
        std::vector<int> ans;
        while ((int)q.size()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (auto v : g[u]) {
                if (--inD[v] == 0) {
                    q.push(v);
                }
            }
        }
        if ((int)ans.size() == numCourses) return ans;
        ans.clear();
        return ans;
    }
};

signed main() {
    //
}

/*

topological sorting

*/