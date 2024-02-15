// BISMILLAH

// Problem link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-interview-150

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
    TreeNode* build(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        TreeNode* last = root;
        if (l != NULL) {
            root->right = l;
            root->left = NULL;
            last = build(l);
            last->right = r;
            last->left = NULL;
        }
        if (r != NULL){
            last = build(r);
        }
        return last;
    }
    void flatten(TreeNode* root) {
        build(root);
    }
};

signed main() {
    //
}

/*

Preorder traversal, return last visited node
in place, O(1) space

*/