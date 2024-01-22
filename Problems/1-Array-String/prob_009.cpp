// BISMILLAH

#include <bits/stdc++.h>

bool canJump(std::vector<int>& nums) {
    std::vector<int> null_pos;
    int N = (int)nums.size();
    for (int i = 0; i < N-1; i++) {
        if (nums[i] == 0) null_pos.push_back(i);
    }
    reverse(null_pos.begin(), null_pos.end());
    int at = 0;
    while ((int)null_pos.size() && at < N-1 && at < null_pos.back()) {
        int cur = nums[at];
        if (cur+at <= null_pos.back()) at++;
        else null_pos.pop_back();
    }

    return (int)null_pos.size() == 0;
}


signed main() {
	//
}

/*

https://leetcode.com/problems/jump-game/?envType=study-plan-v2&envId=top-interview-150

Constructive, find 0 val position
and then try to remove them
using prev idx operations

O(N) time

*/
