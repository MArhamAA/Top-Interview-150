// BISMILLAH

#include <bits/stdc++.h>

class RandomizedSet {
public:
    std::unordered_map<int, int> ds;
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if (ds.find(val) == ds.end()) {
            ds[val] = 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (ds.find(val) != ds.end()) {
            ds.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        if ((int)ds.size() == 1) return ds.begin()->first;
        else {
            int N = std::min(10, (int)ds.size());
            auto it = ds.begin();
            int val = rand()%N;
            while (val--) it++;
            return it->first;
        }
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

signed main() {
	//
}

/*

https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150

O(1)

UnorderedMap, rand() for at max 10 vals

*/