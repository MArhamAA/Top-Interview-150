// BISMILLAH

// Problem link: https://leetcode.com/problems/ipo/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        map<int, vector<int>> list;
        priority_queue<int> best;

        int N = (int)profits.size();
        for (int i = 0; i < N; i++) {
            int p = profits[i];
            int c = capital[i];
            list[c].push_back(p);
        }

        while (k && (int)list.size()) {
            auto it = list.upper_bound(w);
            if (it == list.begin()) {
                if ((int)best.size() == 0) break;
                w += best.top();
                best.pop();
                k -= 1;
                continue;
            }

            vector<int> del;

            for (auto jt = list.begin(); jt != it; jt++) {
                for (auto v : jt->second) {
                    best.push(v);
                }
                del.push_back(jt->first);
            }

            for (auto d : del) list.erase(d);
            
            w += best.top();
            best.pop();
            k -= 1;
        }

        while (k && (int)best.size()) {
            w += best.top();
            best.pop();
            k -= 1;
        }

        return w;
    }
};

signed main() {
    //
}

/*

priority_queue, hashmap, upper_bound

*/