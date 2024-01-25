// BISMILLAH

// Problem link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int N = (int)numbers.size();
    int second = N-1;
    std::vector<int> ans;

    for (int first = 0; first < second; first++) {
        while (numbers[first] + numbers[second] > target && first < second) {
            second--;
        }
        if (numbers[first] + numbers[second] == target && first < second) {
            ans.push_back(first+1);
            ans.push_back(second+1);
        }
    }
    
    return ans;
}

signed main() {
    //
}

/*

TwoSum using 2-pointers

*/