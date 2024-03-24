// BISMILLAH

// Problem link: https://leetcode.com/problems/reverse-nodes-in-k-group/?envType=study-plan-v2&envId=top-interview-150

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;

        ListNode* cur = head, *temp, *temp_next, *temp_next_next;
        ListNode* segment_head = head, *last_segment_end = NULL;
        int k_count = 1;
        while (cur != NULL) {
            if (k_count == k) {
                k_count = 1;
                temp = segment_head;
                temp_next = temp->next;
                while (k_count != k) {
                    if (temp_next != NULL) {
                        temp_next_next = temp_next->next;
                    } else {
                        temp_next_next = NULL;
                    }
                    temp_next->next = temp;
                    temp = temp_next;
                    temp_next = temp_next_next;
                    k_count++;
                }
                if (last_segment_end == NULL) {
                    // head case
                    head = temp;
                } else {
                    last_segment_end->next = temp;
                }
                last_segment_end = segment_head;
                segment_head->next = temp_next;
                segment_head = temp_next;
                k_count = 1;
                cur = temp_next;
            } else {
                k_count++;
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

"maintain segment: head, last_segment
pairwise swap concept"

O(1) extra space

*/