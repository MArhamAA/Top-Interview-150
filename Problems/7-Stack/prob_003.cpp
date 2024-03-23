// BISMILLAH

// Problem link: https://leetcode.com/problems/min-stack/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class MinStack {
public:
    std::vector<int> st, mn_val;
    MinStack() {}
    
    void push(int val) {
        if (st.empty()) {
            mn_val.push_back(val);
        } else {
            mn_val.push_back(std::min(mn_val.back(), val));
        }
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
        mn_val.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return mn_val.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

signed main() {
    //
}

/*

each node in stack contains min_val

O(1) time

*/