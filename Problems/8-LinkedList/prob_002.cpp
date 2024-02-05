// BISMILLAH

// Problem link: https://leetcode.com/problems/add-two-numbers/?envType=study-plan-v2&envId=top-interview-150

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans, *cur;
        ans = cur = nullptr;
        int carry = 0, sum;

        while (l1 != nullptr && l2 != nullptr) {
            sum = carry + l1->val + l2->val;
            ListNode *newNode = new ListNode(sum%10);

            if (ans == nullptr) {
                ans = cur = newNode;
            } else {
                cur->next = newNode;
                cur = newNode;
            }

            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;

        }

        while (l1 != nullptr) {
            sum = carry + l1->val;
            ListNode *newNode = new ListNode(sum%10);

            cur->next = newNode;
            cur = newNode;

            carry = sum/10;
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            sum = carry + l2->val;
            ListNode *newNode = new ListNode(sum%10);

            cur->next = newNode;
            cur = newNode;

            carry = sum/10;
            l2 = l2->next;
        }

        if (carry) {
            ListNode *newNode = new ListNode(carry);

            cur->next = newNode;
            cur = newNode;
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