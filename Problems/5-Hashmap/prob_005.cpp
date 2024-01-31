// BISMILLAH

// Problem link: https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::string> a = strs;
        for (auto &i : a) sort(i.begin(), i.end());

        std::unordered_map<std::string,std::vector<int>> list;
        int idx = 0;
        for (auto i : a) {
            list[i].push_back(idx++);
        }

        std::vector<std::vector<std::string>> ans;
        for (auto i : list) {
            std::vector<std::string> local;
            for (auto j : i.second) {
                local.push_back(strs[j]);
            }
            ans.push_back(local);
        }

        return ans;
    }
};

signed main() {
    //
}

/*

2D Freq Array

*/