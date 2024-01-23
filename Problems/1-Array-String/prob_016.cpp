// BISMILLAH

#include "bits/stdc++.h"

int trap(std::vector<int>& height) {
    int N = (int)height.size();
    int LR[N][2]; memset(LR, -1, sizeof(LR));
    std::vector<int> st; st.push_back(0);
    for (int i = 1; i < N; i++) {
        while ((int)st.size() && height[st.back()] <= height[i]) {
            st.pop_back();
        }
        if ((int)st.size()) {
            LR[i][0] = st.back();
        }
        st.push_back(i);
    }
    st.clear();
    st.push_back(N-1);
    for (int i = N-2; i >= 0; i--) {
        while ((int)st.size() && height[st.back()] <= height[i]) {
            st.pop_back();
        }
        if ((int)st.size()) {
            LR[i][1] = st.back();
        }
        st.push_back(i);
    }

    int ans = 0;
    std::map<std::vector<int>, bool> used;

    for (int i = 0; i < N; i++) {
        if (std::min(LR[i][0], LR[i][1]) == -1) continue;
        if (used.find({height[i], LR[i][0], LR[i][1]}) != used.end()) continue;
        int mn_H = std::min(height[LR[i][0]], height[LR[i][1]]);
        used[{height[i], LR[i][0], LR[i][1]}] = 1;
        ans += (mn_H-height[i])*(LR[i][1] - LR[i][0] - 1);
    }

    return ans;
}

signed main() {
    //
}

/*

https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150

NGR, NGL using stack

O(N lg N) time

*/