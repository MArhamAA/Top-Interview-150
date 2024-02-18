// BISMILLAH

// Problem link: https://leetcode.com/problems/validate-binary-search-tree/description/?envType=study-plan-v2&envId=top-interview-150

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
    bool isValidBST(TreeNode* root) {
        dfs(root);
        for (int i = 0; i < (int)a.size()-1; i++) {
            if (a[i] >= a[i+1]) {
                return false;
            }
        }
        return true;
    }
};

signed main() {
    //
}

/*

dfs, copy from prev problem

*/