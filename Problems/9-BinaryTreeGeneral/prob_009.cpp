// BISMILLAH

// Problem link: https://leetcode.com/problems/path-sum/description/?envType=study-plan-v2&envId=top-interview-150

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
    bool hasPathSum(TreeNode* root, int targetSum, int sum=0) {
        if (root == NULL) {
            return 0;
        }
        int val = root->val;
        if (root->left == NULL && root->right == NULL) {
            // leaf
            return (sum+val) == targetSum;
        }
        return hasPathSum(root->left,targetSum,sum+val)||hasPathSum(root->right,targetSum,sum+val);
    }
};

signed main() {
    //
}

/*

DFS

*/