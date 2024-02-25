// BISMILLAH

// Problem link: https://leetcode.com/problems/implement-trie-prefix-tree/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class Trie {
public:
    int T[500005][26], root, used;
    bool mark[500005];
    Trie() {
        root = 0;
        memset(mark, 0, sizeof(mark));
        memset(T, -1, sizeof(T));
        used = 0;
    }
    
    void insert(string word) {
        int cur = root;
        for (auto i : word) {
            int n = i-'a';
            if (T[cur][n] == -1) {
                T[cur][n] = ++used;
            }
            cur = T[cur][n];
        }
        mark[cur] = 1;
    }
    
    bool search(string word) {
        int cur = root;
        for (auto i : word) {
            int n = i-'a';
            if (T[cur][n] == -1) {
                return false;
            }
            cur = T[cur][n];
        }
        return mark[cur];
    }
    
    bool startsWith(string prefix) {
        int cur = root;
        for (auto i : prefix) {
            int n = i-'a';
            if (T[cur][n] == -1) {
                return false;
            }
            cur = T[cur][n];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

signed main() {
    //
}

/*

Trie implementation using array

*/