// BISMILLAH

// Problem link: https://leetcode.com/problems/average-of-levels-in-binary-tree/description/?envType=study-plan-v2&envId=top-interview-150

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
    std::unordered_map<int,long long> sum;
    std::unordered_map<int,int> count;
    void dfs(TreeNode* root, int L, int &mxL) {
        if (root == NULL) {
            return;
        }
        mxL = std::max(mxL, L);
        sum[L] += root->val;
        count[L]++;
        dfs(root->left, L+1, mxL);
        dfs(root->right, L+1, mxL);
    }
    std::vector<double> averageOfLevels(TreeNode* root) {
        int mxL = -1;
        dfs(root, 0, mxL);
        std::vector<double> ans;
        for (int l = 0; l <= mxL; l++) {
            ans.push_back(sum[l]*1.0/count[l]);
        }
        return ans;
    }
};

signed main() {
    //
}

/*

dfs, levelwise
overflow issue

*/