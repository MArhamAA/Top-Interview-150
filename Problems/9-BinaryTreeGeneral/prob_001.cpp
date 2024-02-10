// BISMILLAH

// Problem link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int fn(TreeNode* root, int &res) {
        if (root == NULL) {
            return 0;
        }
        int l = fn(root->left, res);
        int r = fn(root->right, res);
        res = std::max(l, r)+1;
        return res;
    }
    int maxDepth(TreeNode* root) {
        // if (root == NULL) {
        //     return 0;
        // }
        // if (root->left == NULL && root->right == NULL) {
        //     return 1;
        // }
        int ans = 0;
        fn(root, ans);
        return ans;
    }
};

signed main() {
    //
}

/*

DP on tree
max ans from left, right sub tree

*/