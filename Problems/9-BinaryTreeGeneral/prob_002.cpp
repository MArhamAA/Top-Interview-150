// BISMILLAH

// Problem link: https://leetcode.com/problems/same-tree/description/?envType=study-plan-v2&envId=top-interview-150

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL) {
            return q == NULL ? 1 : 0;
        }
        if (q == NULL) {
            return p == NULL ? 1 : 0;
        }
        bool local = p->val == q->val ? 1 : 0;
        int l = isSameTree(p->left, q->left);
        int r = isSameTree(p->right, q->right);
        return l && r && local;
    }
};

signed main() {
    //
}

/*

DP on tree
check for both left, right sub tree

*/