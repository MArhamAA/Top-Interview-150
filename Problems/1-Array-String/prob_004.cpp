// BISMILLAH

#include <bits/stdc++.h>

int removeDuplicates(std::vector<int>& nums) {
    int ans = 0;

    int cur = -10001, done = 0, _val = -10001, N = (int)nums.size();
    for (int i = 0,c=0; i < N; c++,i++) {
        if (_val == nums[i]) {
            continue;
        }
        else if (cur == nums[i]) {
            if (done) {
                nums[i] = _val;
            } else done = 1, ans++;
        } else {
            done = 0;
            cur = nums[i];
            ans++;
        }
    }

    // for (auto i : nums) printf("%d ",i);
    int go=-1;
    for (int i = 0; i < N; i++) {
        if (nums[i] == _val) {
            go = i;
            break;
        }
    }

    if (go != -1) {
        for (int i = go+1; i < N; i++) {
            if (nums[i] != _val) {
                std::swap(nums[go],nums[i]);
                for (int j = go+1; j <= i; j++) {
                    if (nums[j] == _val) {
                        go = j;
                        break;
                    }
                }
            }
        }
    }

    return ans;
}

signed main() {
	//
}

/*

https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150

Kinda Two Pointers, O(N) time

Extra Space: O(1), In-place

*/