// BISMILLAH

// Problem link: https://leetcode.com/problems/insert-interval/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        int N = (int)intervals.size();
        int first = -1, second;
        std::vector<std::vector<int>> ans;

        for (int i = 0; i < N; i++) {
            if (newInterval[0] > intervals[i][0]) {
                first = i;
            }
        }
        if (first == -1) {
            for (int i = 0; i < N; i++) {
                if (newInterval[1] < intervals[i][0]) {
                    second = i;
                    break;
                }
            }
            if (second) newInterval[1] = std::max(newInterval[1], intervals[second-1][1]);
            ans.push_back(newInterval);
            for (int i = second; i < N; i++) {
                ans.push_back(intervals[i]);
            }
        } else {
            if (intervals[first][1] >= newInterval[0]) {
                newInterval[0] = intervals[first][0];
                newInterval[1] = std::max(newInterval[1], intervals[first][1]);
                first--;
            }
            for (int i = 0; i <= first; i++) {
                ans.push_back(intervals[i]);
            }
            second = N;
            for (int i = 0; i < N; i++) {
                if (intervals[i][0] > newInterval[1]) {
                    second = i;
                    break;
                }
                newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            }
            ans.push_back(newInterval);
            for (int i = second; i < N; i++) {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};

signed main() {
    //
}

/*

Implementation, greedy
time O(N)

*/