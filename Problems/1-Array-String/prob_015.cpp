 // BISMILLAH

#include <bits/stdc++.h>
 
 int candy(std::vector<int>& ratings) {
    std::vector<int> st;
    int N = (int)ratings.size();
    std::vector<int> g[N], a(N, 0), inD(N, 0);

    for (int i = 0; i < N-1; i++) {
        if (ratings[i] < ratings[i+1]) {
            g[i].push_back(i+1);
            inD[i+1]++;
        } else if (ratings[i] > ratings[i+1]) {
            g[i+1].push_back(i);
            inD[i]++;
        }
    }

    std::function<void(void)> topo = [&] () {
        std::queue<int> q;
        for (int i = 0; i < N; i++) {
            if (inD[i] == 0) {
                q.push(i);
                a[i] = 1;
            }
        }
        while ((int)q.size()) {
            int x = q.front();
            q.pop();
            for (auto v : g[x]) {
                inD[v]--;
                a[v] = std::max(a[v], a[x]+1);
                if (inD[v] == 0) q.push(v);
            }
        }
    }; topo();

    return accumulate(a.begin(), a.end(), 0);
    
}

signed main() {
	//
}

/*

https://leetcode.com/problems/candy/description/?envType=study-plan-v2&envId=top-interview-150

Dependency Graph, Topo Sort

*/