// BISMILLAH

// Problem link: https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=study-plan-v2&envId=top-interview-150

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *cur = head, *l, *r, *l_prev = nullptr, *r_next;
        int L = 1;
        while (L < left) {
            l_prev = cur;
            cur = cur->next;
            L++;
        }
        l = cur;
        int R = L;
        while (R < right) {
            cur = cur->next;
            R++;
        }
        r = cur;
        r_next = cur->next;
        
        ListNode *newHead = NULL, *newTail;

        while (true) {
            ListNode *node = new ListNode(l->val);
            // printf("%d\n",l->val);
            if (newHead == NULL) {
                newHead = newTail = node;
            } else {
                node->next = newHead;
                newHead = node;
            }
            // printf("%d %d\n",newHead->val, newTail->val);
            l = l->next;
            if (L++ == R) break;
        }

        if (l_prev != NULL) {
            l_prev->next = newHead;
        } else {
            head = newHead;
        }
        newTail->next = r_next;

        return head;
    }
};

signed main() {
    //
}

/*

Linked List traversal using pointer

*/