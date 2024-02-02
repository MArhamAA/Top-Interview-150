// BISMILLAH

// Problem link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        int N = (int)points.size();
        sort(points.begin(), points.end());

        int ans = 1;

        int first = 0, lim = points[0][1];
        for (int second = 0; second < N; second++) {
            if (lim >= points[second][0]) {
                lim = std::min(lim, points[second][1]);
            } else {
                ans++;
                first = second;
                lim = points[second][1];
            }
        }

        return ans;

    }
};

signed main() {
    //
}

/*

observation, sorting
time O(N lgN)

*/