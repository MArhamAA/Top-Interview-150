// BISMILLAH

#include <bits/stdc++.h>

int removeElement(std::vector<int>& nums, int val) {
    std::vector<int> ans;
    for (auto i : nums) {
        if (i != val) ans.push_back(i);
    }

    nums = ans;
    return (int)ans.size();
}

signed main() {
    //
}

/*

https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

Iteration over array

*/