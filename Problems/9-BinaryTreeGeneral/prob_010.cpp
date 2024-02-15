// BISMILLAH

// Problem link: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=study-plan-v2&envId=top-interview-150

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
    int sumNumbers(TreeNode* root, std::string s="") {
        if (root == NULL) {
            return 0;
        }
        s += (root->val+'0');
        if (root->left == NULL && root->right == NULL) {
            // leaf
            return stoi(s);
        }
        return sumNumbers(root->left, s) + sumNumbers(root->right, s);
    }
};

signed main() {
    //
}

/*

DFS

*/