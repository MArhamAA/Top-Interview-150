// BISMILLAH

// Problem link: https://leetcode.com/problems/sort-list/description/?envType=study-plan-v2&envId=top-interview-150

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
    int N;
    ListNode* merge_sort(ListNode* h, int l, int r) {
        if (l > r) return NULL;
        if (l == r) {
            return h;
        }

        int m = l+(r-l)/2;
        ListNode* right_head = h;
        int count = l;
        while (count <= m) {
            right_head = right_head->next;
            count++;
        }

        ListNode* L = merge_sort(h, l, m);
        ListNode* R = merge_sort(right_head, m+1, r);

        int count_l = l, count_r = m+1;

        ListNode* last_inserted = NULL, *root, *l_next, *r_next;
        while (count_l <= m && count_r <= r) {
            l_next = L->next, r_next = R->next;
            if (L->val <= R->val) {
                if (last_inserted == NULL) {
                    root = last_inserted = L;
                } else {
                    last_inserted->next = L;
                    last_inserted = last_inserted->next;
                }
                L = l_next;
                count_l++;
            } else {
                if (last_inserted == NULL) {
                    root = last_inserted = R;
                } else {
                    last_inserted->next = R;
                    last_inserted = last_inserted->next;
                }
                R = r_next;
                count_r++;
            }
        }

        if (count_l <= m) {
            while (count_l <= m) {
                last_inserted->next = L;
                last_inserted = last_inserted->next;
                L = L->next;
                count_l++;
            }
            last_inserted->next = r_next;
        } else {
            while (count_r <= r) {
                last_inserted->next = R;
                last_inserted = last_inserted->next;
                R = R->next;
                count_r++;
            }
            last_inserted->next = l_next;
        }

        return root;
    }

    ListNode* sortList(ListNode* head) {
        N = 0;
        ListNode* cur = head;
        while (cur != NULL) {
            N++;
            cur = cur->next;
        }
        if (N == 0) return head;

        head = merge_sort(head, 0, N-1);
        cur = head;
        while (N-1 > 0) {
            cur = cur->next;
            N--;
        }
        cur->next = NULL;
        return head;
    }
};

signed main() {
    //
}

/*

merge sort algorithmmerge sort algorithm, left-right segment

"O(N lg N) time
O(1) extra space-
ignoring recurson stack"

*/