// BISMILLAH

// Problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/?envType=study-plan-v2&envId=top-interview-150

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *l, *r, *newList = NULL;
        l = r = head;

        head = NULL;

        while (r != NULL) {
            // printf("%d %d\n",l->val, r->val);
            while (r != NULL && l->val == r->val) {
                r = r->next;
            }
            if (l->next == r) {
                if (newList == NULL) {
                    head = newList = l;
                } else {
                    newList->next = l;
                    newList = l;
                }
            }
            l = r;
        }

        if (newList != NULL) {
            newList->next = NULL;
        }

        return head;

    }
};

signed main() {
    //
}

/*

sliding window approach

*/