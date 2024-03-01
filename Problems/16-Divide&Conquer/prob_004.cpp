// BISMILLAH

// Problem link: https://leetcode.com/problems/merge-k-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150

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
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* root = NULL, *cur;
        while (a != NULL && b != NULL) {
            if (a->val <= b->val) {
                ListNode* newNode = new ListNode(a->val);
                if (root == NULL) {
                    root = cur = newNode;
                } else {
                    cur->next = newNode;
                    cur = newNode;
                }
                a = a->next;
            } else {
                ListNode* newNode = new ListNode(b->val);
                if (root == NULL) {
                    root = cur = newNode;
                } else {
                    cur->next = newNode;
                    cur = newNode;
                }
                b = b->next;
            }
        }

        while (a != NULL) {
            ListNode* newNode = new ListNode(a->val);
            if (root == NULL) {
                root = cur = newNode;
            } else {
                cur->next = newNode;
                cur = newNode;
            }
            a = a->next;
        }

        while (b != NULL) {
            ListNode* newNode = new ListNode(b->val);
            if (root == NULL) {
                root = cur = newNode;
            } else {
                cur->next = newNode;
                cur = newNode;
            }
            b = b->next;
        }

        return root;
    }

    ListNode* fn(int l, int r, std::vector<ListNode*>& list) {
        if (l > r) return NULL;
        if (l == r) return list[l];
        int m = l+(r-l)/2;
        ListNode* L = fn(l, m, list);
        ListNode* R = fn(m+1, r, list);
        return merge(L, R);
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        return fn(0, (int)lists.size()-1, lists);
    }
};

signed main() {
    //
}

/*

merge sort algorithm

*/