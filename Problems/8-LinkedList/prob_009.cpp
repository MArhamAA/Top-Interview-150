// BISMILLAH

// Problem link: https://leetcode.com/problems/rotate-list/description/?envType=study-plan-v2&envId=top-interview-150

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
    ListNode* rotateRight(ListNode* head, int k) {
        int N = 0;
        ListNode *cur = head, *last;
        while (cur != NULL) {
            N++;
            cur = cur->next;
        }
        if (N < 2) return head;

        k %= N;
        cur = head;
        while (cur->next != NULL) {
            last = cur;
            cur = cur->next;
        }
        while (k--) {
            cur->next = head;
            last->next = NULL;
            head = cur;
            while (cur->next != NULL) {
                last = cur;
                cur = cur->next;
            }

        }

        return head;
    }
};

signed main() {
    //
}

/*

array right rotation

*/