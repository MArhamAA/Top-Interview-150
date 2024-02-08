// BISMILLAH

// Problem link: https://leetcode.com/problems/partition-list/description/?envType=study-plan-v2&envId=top-interview-150

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *first = NULL, *prev_first = NULL, *cur = head;
        while (cur != NULL) {
            if (cur->val >= x) {
                first = cur;
                break;
            }
            prev_first = cur;
            cur = cur->next;
        }

        if (first != NULL) {
            while (true) {
                cur = first->next;
                ListNode *next_small = NULL, *prev, *next;

                cur = first->next;
                prev = first;

                while (cur != NULL) {
                    if (cur->val < x) {
                        next_small = cur;
                        break;
                    }
                    prev = cur;
                    cur = cur->next;
                }

                if (next_small == NULL) break;

                prev->next = next_small->next;
                next_small->next = first;

                if (prev_first == NULL) {
                    head = next_small;
                } else {
                    prev_first->next = next_small;
                }

                prev_first = next_small;
            }
        }

        return head;
    }
};

signed main() {
    //
}

/*

bruteforce, greedy

*/