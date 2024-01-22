// BISMILLAH

#include <bits/stdc++.h>

int majorityElement(std::vector<int>& nums) {
    std::unordered_map<int,int> count;
    for (auto i : nums) {
        count[i]++;
    }
    int ans, tot = 0;
    for (auto i : count) {
        if (i.second > tot) {
            tot = i.second;
            ans = i.first;
        }
    }
    return ans;
}

signed main() {
	//
}

/*

https://leetcode.com/problems/majority-element/?envType=study-plan-v2&envId=top-interview-150

Hashmap

Boyer–Moore majority vote algorithm

*/