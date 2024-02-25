// BISMILLAH

// Problem link: https://leetcode.com/problems/design-add-and-search-words-data-structure/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class WordDictionary {
public:
    int T[300005][26], root, used;
    bool mark[300005];
    WordDictionary() {
        root = 0;
        memset(mark, 0, sizeof(mark));
        memset(T, -1, sizeof(T));
        used = 0;
    }
    
    void addWord(string word) {
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

    bool fn(string word, int at, int cur) {
        if (at == (int)word.size()) {
            return mark[cur];
        }
        if (word[at] == '.') {
            bool local = false;
            for (int i = 0; i < 26; i++) {
                if (T[cur][i] != -1) {
                    local |= fn(word, at+1, T[cur][i]);
                }
            }
            return local;
        }
        int n = word[at]-'a';
        if (T[cur][n] == -1) {
            return false;
        }
        return fn(word, at+1, T[cur][n]);
    }
    
    bool search(string word) {
        return fn(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

signed main() {
    //
}

/*

Trie & recursion

*/