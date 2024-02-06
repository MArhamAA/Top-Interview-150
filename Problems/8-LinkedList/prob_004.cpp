// BISMILLAH

// Problem link: https://leetcode.com/problems/copy-list-with-random-pointer/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *ans = NULL, *ans_cur, *cur = head, *newNode, *node;

        while (cur != NULL) {
            newNode = new Node(cur->val);
            if (ans == NULL) {
                ans = ans_cur = newNode;
            } else {
                ans_cur->next = newNode;
                ans_cur = newNode;
            }
            cur = cur->next;
        }

        cur = head, ans_cur = ans;
        while (cur != NULL) {
            if (cur->random != NULL) {
                int idx = 0;
                node = head;
                while (cur->random != node) {
                    node = node->next;
                    idx++;
                }
                node = ans;
                while (idx--) {
                    node = node->next;
                }
                ans_cur->random = node;
            }

            cur = cur->next;
            ans_cur = ans_cur->next;
        }

        return ans;
    }
};

signed main() {
    //
}

/*

Linked List traversal using pointer

*/