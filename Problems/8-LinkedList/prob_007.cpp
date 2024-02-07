// BISMILLAH

// Problem link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<ListNode*> al(35);
        ListNode *cur = head;
        int N = 0;

        while (cur != NULL) {
            al[++N] = cur;
            cur = cur->next;
        }

        int at = N-n;
        if (at == 0) {
            head = head->next;
        } else {
            al[at]->next = al[at+1]->next;
        }

        return head;
    }
};

signed main() {
    //
}

/*

store each node in an array
one pass

*/