// BISMILLAH

// Problem link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150

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
    TreeNode* build(TreeNode* root, int at, int L, int R, std::vector<int> pre, std::vector<int> in) {
        if (L > R) return NULL;
        TreeNode* l, *r;
        int pos;
        for (int i = L; i <= R; i++) {
            if (in[i] == pre[at]) {
                pos = i;
                break;
            }
        }
        l = build(l, at+1, L, pos-1, pre, in);
        r = build(r, at+(pos-L)+1, pos+1, R, pre, in);
        TreeNode* newNode = new TreeNode(pre[at], l, r);
        return root = newNode;
    }
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        TreeNode* root = NULL;
        return build(root, 0, 0, (int)preorder.size()-1, preorder, inorder);
    }
};

signed main() {
    //
}

/*

PreO gives root val, InO gives left/right

*/