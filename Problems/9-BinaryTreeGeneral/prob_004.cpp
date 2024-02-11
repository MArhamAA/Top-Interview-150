// BISMILLAH

// Problem link: https://leetcode.com/problems/symmetric-tree/description/?envType=study-plan-v2&envId=top-interview-150

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

#define pli std::pair<TreeNode*,int>

class Solution {
public:
    bool sym(TreeNode* l, TreeNode* r) {
        if (l == NULL) {
            return r==NULL ? 1:0;
        }
        if (r == NULL) {
            return l==NULL ? 1:0;
        }
        if (l->val != r->val) {
            return 0;
        }
        return sym(l->left, r->right) && sym(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        // return sym(root->left, root->right);
        TreeNode *l = root->left, *r = root->right;
        if (l == NULL && r == NULL) return 1;
        if (l == NULL || r == NULL) return 0;

        std::vector<std::pair<int,int>> left_sub;
        std::queue<pli> q;
        q.push(pli(l, 0));
        while ((int)q.size()) {
            l = q.front().first;
            int stat = q.front().second;
            q.pop();
            if (l == NULL) {
                left_sub.push_back({0,stat});
                continue;
            }
            left_sub.push_back({l->val,stat});
            if (l->left != NULL) {
                q.push(pli(l->left, -1));
            } else {
                q.push(pli(NULL, 2));
            }
            if (l->right != NULL) {
                q.push(pli(l->right, 1));
            } else {
                q.push(pli(NULL, 2));
            }
        }
        reverse(left_sub.begin(), left_sub.end());
        q.push(pli(r, 0));
        bool ans = 1;
        while ((int)q.size()) {
            r = q.front().first;
            int stat = q.front().second;
            q.pop();
            if ((int)left_sub.size() == 0) {
                ans = 0;
                break;
            }
            if (left_sub.back().second != stat) {
                ans = 0;
                break;
            }
            if (r != NULL && left_sub.back().first != r->val) {
                ans = 0;
                break;
            }
            left_sub.pop_back();
            if (r == NULL) continue;
            if (r->right != NULL) {
                q.push(pli(r->right, -1));
            } else {
                q.push(pli(NULL, 2));
            }
            if (r->left != NULL) {
                q.push(pli(r->left, 1));
            } else {
                q.push(pli(NULL, 2));
            }
        }

        if ((int)left_sub.size()) ans = 0;

        return ans;
    }
};

signed main() {
    //
}

/*

BFS for iterative, left, right state rep

*/