// BISMILLAH

// Problem link: https://leetcode.com/problems/binary-search-tree-iterator/description/?envType=study-plan-v2&envId=top-interview-150

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

class BSTIterator {
public:
    std::vector<int> vals;
    int at;
    void dfs(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        dfs(root->left);
        vals.push_back(root->val);
        dfs(root->right);
    }
    BSTIterator(TreeNode* root) {
        dfs(root);
        at = 0;
    }
    
    int next() {
        return vals[at++];
    }
    
    bool hasNext() {
        return at+1 <= (int)vals.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

signed main() {
    //
}

/*

DFS

*/