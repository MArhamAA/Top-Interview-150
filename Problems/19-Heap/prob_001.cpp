// BISMILLAH

// Problem link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int H[100005], last_inserted = 0;  // 1-based idx

    void insert(int val) {
        H[++last_inserted] = val;
        int idx = last_inserted;
        while (idx > 1) {
            int par = idx/2;
            if (H[par] < H[idx]) {
                std::swap(H[par], H[idx]);
                idx = par;
            }
            else break;
        }
    }

    int delete_top() {
        assert(last_inserted > 0);
        int top = H[1];
        std::swap(H[1], H[last_inserted--]);

        int idx = 1;
        while (idx*2 <= last_inserted) {
            int left_child = 2*idx;
            int right_child = 2*idx+1;
            if (H[left_child] > H[right_child] || right_child > last_inserted) {
                if (H[idx] < H[left_child]) {
                    std::swap(H[left_child], H[idx]);
                    idx = left_child;
                }
                else break;
            } else {
                if (H[idx] < H[right_child]) {
                    std::swap(H[right_child], H[idx]);
                    idx = right_child;
                }
                else break;
            }
        }

        return top;
    }

    int findKthLargest(std::vector<int>& nums, int k) {
        for (auto i : nums) insert(i);
        int ans;
        while (k--) {
            ans = delete_top();
        }
        return ans;
    }
};

signed main() {
    //
}

/*

priority_queue, max_heap

*/