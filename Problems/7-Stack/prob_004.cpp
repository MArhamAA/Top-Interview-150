// BISMILLAH

// Problem link: https://leetcode.com/problems/evaluate-reverse-polish-notation/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int isOp(std::string s) {
        if ((int)s.size()==1) {
            switch(s[0]) {
                case '+':
                    return 0;
                case '-':
                    return 1;
                case '*':
                    return 2;
                case '/':
                    return 3;
            }
        }
        return -1;
    }
    int evalRPN(std::vector<std::string>& tokens) {
        std::vector<int> ans;
        for (auto i : tokens) {
            int ret = isOp(i);
            if (ret == -1) {
                ans.push_back(stoi(i));
            } else {
                int a = ans.back(); ans.pop_back();
                int b = ans.back(); ans.pop_back();
                if (ret == 0) {
                    ans.push_back(a+b);
                } else if (ret == 1) {
                    ans.push_back(b-a);
                } else if (ret == 2) {
                    ans.push_back(a*b);
                } else {
                    ans.push_back(b/a);
                }
            }
            // for (auto j : ans) printf("%d ",j); printf("\n");
        }

        return ans.back();
    }
};

signed main() {
    //
}

/*

LIFO

*/