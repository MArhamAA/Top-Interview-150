// BISMILLAH

// Problem link: https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans = NULL, *cur;

        while (list1 != NULL && list2 != NULL) {
            ListNode *newNode;
            if (list1->val <= list2->val) {
                newNode = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                newNode = new ListNode(list2->val);
                list2 = list2->next;
            }

            if (ans == NULL) {
                ans = cur = newNode;
            } else {
                cur->next = newNode;
                cur = newNode;
            }

        }
        
        while (list1 != NULL) {
            ListNode *newNode;
            newNode = new ListNode(list1->val);
            if (ans == NULL) {
                ans = cur = newNode;
            } else {
                cur->next = newNode;
                cur = newNode;
            }
            list1 = list1->next;
        }

        while (list2 != NULL) {
            ListNode *newNode;
            newNode = new ListNode(list2->val);
            if (ans == NULL) {
                ans = cur = newNode;
            } else {
                cur->next = newNode;
                cur = newNode;
            }
            list2 = list2->next;
        }

        return ans;

    }
};

signed main() {
    //
}

/*

Linked List using pointer & merge

*/