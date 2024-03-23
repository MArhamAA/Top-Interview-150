// BISMILLAH

// Problem link: https://leetcode.com/problems/longest-consecutive-sequence/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> used, front, back, size;
        for (auto i : nums) {
            if (used.find(i) != used.end()) continue;
            used[i] = 1;
            int f = i-1, b = i+1;
            if (used.find(f) != used.end() && used.find(b) != used.end()) {
                // middle
                // merge two set
                f = front[f];
                b = back[b];
                size[i] = size[f] + size[b] + 1;
                size[f] = size[b] = size[i];
                back[i] = back[b] = back[f] = b;
                front[i] = front[f] = front[b] = f;
            } else if (used.find(f) != used.end()) {
                // push_back
                f = front[f];
                size[i] = size[f] + 1;
                size[f] = size[i];
                back[f] = back[i] = i;
                front[i] = front[f] = f;
            } else if (used.find(b) != used.end()) {
                // push_front
                b = back[b];
                size[i] = size[b] + 1;
                size[b] = size[i];
                front[i] = front[b] = i;
                back[b] = back[i] = b;
            } else {
                size[i] = 1;
                front[i] = back[i] = i;
            }
        }
        int ans = 0;
        for (auto i : size) {
            ans = max(ans, i.second);
        }
        return ans;
    }
};

signed main() {
    //
}

/*

"front, back, size of any set hashmap; 
set merging concept"

O(N) time

*/