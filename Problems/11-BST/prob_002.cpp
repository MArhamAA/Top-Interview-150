// BISMILLAH

// Problem link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-interview-150

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
    std::vector<int> a;
    void dfs(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        dfs(root->left);
        a.push_back(root->val);
        dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return a[k-1];
    }
};

signed main() {
    //
}

/*

dfs

*/