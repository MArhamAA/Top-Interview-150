// BISMILLAH

// Problem link: https://leetcode.com/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

 // Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *hare, *tortoise;
        hare = tortoise = head;
        bool cyc = 0;

        while (true) {
            if (hare != NULL) hare = hare->next;
            else break;

            if (hare != NULL) hare = hare->next;
            else break;

            tortoise = tortoise->next;
            if (hare == tortoise) {
                cyc = 1;
                break;
            }
        }

        return cyc;
    }
};

signed main() {
    //
}

/*

Hare-Tortoise cycle finding algo
O(1) space

*/