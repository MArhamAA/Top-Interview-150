// BISMILLAH

// Problem link: https://leetcode.com/problems/binary-tree-right-side-view/description/?envType=study-plan-v2&envId=top-interview-150

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
    std::vector<int> ans;
    std::unordered_map<int, int> lev_last;
    void dfs(TreeNode* root, int L, int &mxL) {
        if (root == NULL) {
            return;
        }
        lev_last[L] = root->val;
        mxL = std::max(mxL, L);
        dfs(root->left, L+1, mxL);
        dfs(root->right,L+1, mxL);
    }
    std::vector<int> rightSideView(TreeNode* root) {
        int mxL = -1;
        dfs(root, 0, mxL);
        for (int i = 0; i <= mxL; i++) {
            ans.push_back(lev_last[i]);
        }
        return ans;
    }
};

signed main() {
    //
}

/*

dfs, levelwise

*/