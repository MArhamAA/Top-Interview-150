// BISMILLAH

// Problem link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

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
    std::unordered_map<TreeNode*, bool> yes;
    std::unordered_map<TreeNode*, TreeNode*> par;
    void dfs(TreeNode* u, TreeNode* p, TreeNode* x) {
        if (u == NULL) {
            return;
        }
        par[u] = p;
        if (u == x) {
            return;
        }
        dfs(u->left, u, x);
        dfs(u->right, u, x);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, NULL, p);
        while (p != NULL) {
            yes[p] = 1;
            p = par[p];
        }
        dfs(root, NULL, q);
        TreeNode* ans = NULL;
        while (q != NULL) {
            if (yes[q]) {
                ans = q;
                break;
            }
            q = par[q];
        }
        return ans;
    }
};

signed main() {
    //
}

/*

DFS, bruteforce

*/