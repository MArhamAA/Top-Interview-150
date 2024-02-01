// BISMILLAH

// Problem link: https://leetcode.com/problems/merge-intervals/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        int N = (int)intervals.size();
        sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> ans;
        std::vector<int> internal(2);
        int L = -1, R;
        for (int i = 0; i < N; i++) {
            if (L == -1) {
                L = i;
                R = intervals[i][1];
            } else if (intervals[i][0] <= R) {
                R = std::max(R, intervals[i][1]);
            } else {
                internal[0] = intervals[L][0];
                internal[1] = R;
                ans.push_back(internal);
                L = i;
                R = intervals[i][1];
            }
        }
        internal[0] = intervals[L][0];
        internal[1] = R;
        ans.push_back(internal);

        return ans;
    }
};

signed main() {
    //
}

/*

Implementation, greedy

*/