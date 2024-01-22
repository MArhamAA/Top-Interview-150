// BISMILLAH

#include <bits/stdc++.h>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> ans;
    int suf = 1, N = (int)nums.size();
    int pref[N+1]; pref[N] = 1;

    for (int i = N-1; i >= 0; i--) {
        pref[i] = pref[i+1]*nums[i];
    }

    for (int i = 0; i < N; i++) {
        ans.push_back(pref[i+1]*suf);
        suf *= nums[i];
    }

    return ans;
}

signed main() {
	//
}

/*

https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150

Suf-Pref array, O(N) time

*/