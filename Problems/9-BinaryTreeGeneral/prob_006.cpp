// BISMILLAH

// Problem link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/?envType=study-plan-v2&envId=top-interview-150

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
    TreeNode* build(TreeNode* root, int at, int L, int R, std::vector<int> post, std::vector<int> in) {
        if (L > R) return NULL;
        TreeNode* l, *r;
        int pos;
        for (int i = L; i <= R; i++) {
            if (in[i] == post[at]) {
                pos = i;
                break;
            }
        }
        l = build(l, at-(R-pos+1), L, pos-1, post, in);
        r = build(r, at-1, pos+1, R, post, in);
        TreeNode* newNode = new TreeNode(post[at], l, r);
        return root = newNode;
    }
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        TreeNode* root = NULL;
        return build(root, (int)inorder.size()-1, 0, (int)postorder.size()-1, postorder, inorder);
    }
};

signed main() {
    //
}

/*

PostO gives root val, InO gives left/right

*/