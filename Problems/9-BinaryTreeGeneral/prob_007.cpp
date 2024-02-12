// BISMILLAH

// Problem link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    std::unordered_map<int, Node*> L;
    void NEXT(Node* root, int lev) {
        if (root == NULL) {
            return;
        }
        if (L.find(lev) == L.end()) {
            // first node of current level 'lev'
            L[lev] = root;
        } else {
            L[lev]->next = root;
            L[lev] = root;
        }
        NEXT(root->left, lev+1);
        NEXT(root->right, lev+1);
    }
    Node* connect(Node* root) {
        NEXT(root, 0);
        return root;
    }
};

signed main() {
    //
}

/*

"maintain level of each node and 
corresponding last node of that level"

*/