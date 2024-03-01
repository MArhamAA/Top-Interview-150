// BISMILLAH

// Problem link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int N;
    TreeNode* fn(int l, int r, std::vector<int>& nums) {
        if (l > r) return NULL;
        if (l == r) {
            return new TreeNode(nums[l]);
        }
        int m = l+(r-l)/2;
        TreeNode* L = fn(l, m-1, nums);
        TreeNode* R = fn(m+1, r, nums);

        return new TreeNode(nums[m], L, R);
    }
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        N = (int)nums.size();
        return fn(0, N-1, nums);
    }
};

signed main() {
    //
}

/*

divide the array into two parts, merge them

*/