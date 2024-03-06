// BISMILLAH

// Problem link: https://leetcode.com/problems/max-points-on-a-line/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::vector<int> buildVector(std::vector<int>& a, std::vector<int>& b) {
        return {b[0]-a[0], b[1]-a[1]};
    }
    int vectorCross(std::vector<int>& a, std::vector<int>& b) {
        return a[0]*b[1] - a[1]*b[0];
    }
    int maxPoints(std::vector<std::vector<int>>& points) {
        int N = (int)points.size();
        int ans = 1;
        for (int i = 0; i < N-1; i++) for (int j = i+1; j < N; j++) {
            std::vector<int> A = buildVector(points[i], points[j]);
            int local = 0;
            for (int k = 0; k < N; k++) {
                std::vector<int> B = buildVector(points[i], points[k]);
                if (vectorCross(A,B) == 0) local++;
            }
            ans = std::max(ans, local);
        }
        return ans;
    }
};

signed main() {
    //
}

/*

"bruteforce with each pair, vector cross 
prod, or, slope concept"

*/