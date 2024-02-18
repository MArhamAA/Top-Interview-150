// BISMILLAH

// Problem link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/?envType=study-plan-v2&envId=top-interview-150

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

using pni = std::pair<TreeNode*,int>;
class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        // bfs
        std::queue<pni> q;
        q.push({root, 0});
        while ((int)q.size()) {
            root = q.front().first;
            int l = q.front().second;
            q.pop();
            if (root == NULL) {
                continue;
            }
            if (l+1 > (int)ans.size()) {
                std::vector<int> temp;
                temp.push_back(root->val);
                ans.push_back(temp);
            } else {
                ans[l].push_back(root->val);
            }
            q.push({root->left, l+1});
            q.push({root->right, l+1});
        }
        int at = 0;
        for (auto &i : ans) {
            if (at&1) {
                reverse(i.begin(), i.end());
            }
            at++;
        }
        return ans;
    }
};

signed main() {
    //
}

/*

bfs
copy from prev problem

*/