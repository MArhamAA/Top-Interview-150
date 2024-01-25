// BISMILLAH

// Problem link: https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

int maxArea(std::vector<int>& height) {
    int ans = 0, first = 0, last = (int)height.size()-1;

    auto len = [&] (int l, int r) {
        return r-l;
    };

    auto min = [&] (int i, int j) {
        return std::min(height[i], height[j]);
    };

    while (first < last) {
        ans = std::max(ans, len(first,last)*min(first,last));

        if (height[first] < height[last]) first++;
        else last--;
    }

    return ans;
}

signed main() {
    //
}

/*

Maintain first & last pointer, move min one

*/