// BISMILLAH

// Problem link: https://leetcode.com/problems/lru-cache/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class LRUCache {
public:
    int LIMIT, cur_size;
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) {
            val = v;
            key = k;
            prev = next = NULL;
        }
    } *head, *tail;

    std::unordered_map<int,Node*> cur;

    LRUCache(int capacity) {
        LIMIT = capacity;
        cur_size = 0;
        head = tail = NULL;
    }
    
    int get(int key) {
        if (cur.find(key) == cur.end()) {
            return -1;
        }
        Node *temp = cur[key];
        if (temp != head) {
            if (temp == tail) {
                tail = temp->prev;
                temp->prev->next = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            temp->next = head;
            temp->prev = NULL;
            head->prev = temp;
            head = temp;
        }
        return temp->val;
    }
    
    void put(int key, int value) {
        if (cur.find(key) != cur.end()) {
            Node *temp = cur[key];
            if (temp != head) {
                if (temp == tail) {
                    tail = temp->prev;
                    temp->prev->next = NULL;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                temp->next = head;
                temp->prev = NULL;
                head->prev = temp;
                head = temp;
            }
            temp->val = value;
            return;
        }
        
        if (cur_size == LIMIT) {
            cur.erase(tail->key);
            if (head == tail) {
                head = tail = NULL;
            } else {
                tail->prev->next = NULL;
                tail = tail->prev;
            }
        } else {
            cur_size++;
        }

        Node *newNode = new Node(key,value);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        cur[key] = newNode;

        // Node *test = head;
        // while (test != NULL) {
        //     printf("(%d,%d) -> ",test->key, test->val);
        //     test = test->next;
        // } printf("\n");
        // test = tail;
        // while (test != NULL) {
        //     printf("(%d,%d) -> ",test->key, test->val);
        //     test = test->prev;
        // } printf("\n");
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

signed main() {
    //
}

/*

bruteforce, hashmap, FIFO
avg O(1) time

*/