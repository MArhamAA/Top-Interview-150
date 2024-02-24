// BISMILLAH

// Problem link: https://leetcode.com/problems/clone-graph/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    std::unordered_map<int, Node*> ache;
    Node* dfs(Node* node, Node* root) {
        if (node == NULL) {
            return NULL;
        }
        int u = node->val;
        if (root == NULL) {
            root = new Node(u);
            ache[u] = root;
        }
        std::vector<Node*> list;
        for (auto V : node->neighbors) {
            int v = V->val;
            Node* temp = NULL;
            if (ache.find(v) == ache.end()) {
                temp = new Node(v);
                ache[v] = temp;
                temp = dfs(V, temp);
                // ache[v] = temp;
            } else {
                temp = ache[v];
            }
            list.push_back(temp);
        }
        root->neighbors = list;
        return root;
    }
    Node* cloneGraph(Node* node) {
        Node* root = NULL;
        root = dfs(node, root);
        return root;
    }
};

signed main() {
    //
}

/*

dfs, hashmap

*/