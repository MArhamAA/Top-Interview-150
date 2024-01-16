// BISMILLAH

#include <bits/stdc++.h>

int removeDuplicates(std::vector<int>& nums) {
    std::vector<int> ans;
    std::unordered_map<int,bool> used;

    for (int i : nums) {
        if (used.find(i) == used.end()) {
            ans.push_back(i);
        }
        used[i] = true;
    }

    nums = ans;
    return (int)ans.size();
}

signed main() {
	//
}

/*

https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

Iteration over array & hashmap

*/