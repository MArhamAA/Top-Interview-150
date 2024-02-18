// BISMILLAH

// Problem link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/?envType=study-plan-v2&envId=top-interview-150

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

using pii = std::pair<int,int>;
class Solution {
public:
    pii fn(TreeNode* root, int &ans) {
        if (root == NULL) {
            return {1e9, -1e9};
        }
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        pii fi = fn(l, ans);
        pii se = fn(r, ans);
        ans = std::min(ans, root->val-fi.second);
        ans = std::min(ans, se.first-root->val);
        fi.first = std::min({fi.first, root->val, se.first});
        fi.second = std::max({fi.second, root->val, se.second});
        return fi;
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        fn(root, ans);
        return ans;
    }
};

signed main() {
    //
}

/*

dfs, subtree min, max value

*/