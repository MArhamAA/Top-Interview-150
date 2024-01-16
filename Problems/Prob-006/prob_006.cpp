// BISMILLAH

#include <bits/stdc++.h>

int POS(int i, int j, int N) {
    return (i+j)%N;
}
void rotate(std::vector<int>& nums, int k) {
    int N = (int)nums.size();
    k %= N;
    if (k == 0) return;
    else {
        std::deque<int> d;
        for (auto i : nums) d.push_back(i);
        for (int i = 0; i < k; i++) {
            d.push_front(d.back());
            d.pop_back();
        }
        nums.clear();
        for (auto i : d) nums.push_back(i);
    }
}

signed main() {
	//
}

/*

https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

Deque

In-place

*/