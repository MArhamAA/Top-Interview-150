// BISMILLAH

// Problem link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/?envType=study-plan-v2&envId=top-interview-150

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
    int fn(TreeNode* root, int &ans) {
        if (root == NULL) {
            return -1000000000;
        }
        int l = fn(root->left, ans);
        int r = fn(root->right, ans);
        ans = std::max({ans, l+r+root->val, l, r});
        return std::max(root->val, std::max(l,r)+root->val);
    }
    int maxPathSum(TreeNode* root) {
        int ans = -1000000000;
        ans = std::max(ans, fn(root,ans));
        return ans;
    }
};

signed main() {
    //
}

/*

DP on tree

*/