// BISMILLAH

// Problem link: https://leetcode.com/problems/basic-calculator/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    int calculate(std::string s) {
        std::vector<std::string> st;
        std::vector<std::string> revPolishNotation;
        int N = (int)s.size();

        for (int i = 0; i < N; i++) {
            if (s[i] == ')') {
                while (st.back() != "(") {
                    revPolishNotation.push_back(st.back());
                    st.pop_back();
                } st.pop_back();
            } else if (s[i] == '(') {
                st.push_back("(");
            } else if (s[i] == '+') {
                while ((int)st.size() && st.back() != "(") {
                    revPolishNotation.push_back(st.back());
                    st.pop_back();
                }
                st.push_back("+");
            } else if (s[i] == '-') {
                int last = -1;
                for (int j = i-1; j >= 0; j--) {
                    if (s[j] >= '0' && s[j] <= '9') {
                        last = j;
                        break;
                    } if (s[j] == ')') {
                        last = j;
                        break;
                    } else if (s[j] == '(') {
                        break;
                    }
                }
                if ( last != -1 ) {
                    while ((int)st.size() && st.back() != "(") {
                        revPolishNotation.push_back(st.back());
                        st.pop_back();
                    }
                    st.push_back("-");
                } else {
                    while ((int)st.size() && st.back() != "(") {
                        revPolishNotation.push_back(st.back());
                        st.pop_back();
                    }
                    st.push_back("_");  // unary operation?
                }
            } else if (s[i] >= '0' && s[i] <= '9') {
                std::string val;
                while (i < N && s[i] >= '0' && s[i] <= '9') {
                    val += s[i++];
                }
                i--;
                revPolishNotation.push_back(val);
            }
        }
        while ((int)st.size()) {
            revPolishNotation.push_back(st.back());
            st.pop_back();
        }
        // for (auto i : revPolishNotation) {
        //     std::cout << i << ' ';
        // } std::cout << '\n';
        // return 0;
        
        std::vector<int> ans;
        N = (int)revPolishNotation.size();
        int a,b;

        for (std::string i : revPolishNotation) {
            if (i[0] >= '0' && i[0] <= '9') {
                ans.push_back(stoi(i));
            } else if (i[0] == '+') {
                a = ans.back(); ans.pop_back();
                b = ans.back(); ans.pop_back();
                ans.push_back(a+b);
            } else if (i[0] == '_') {
                a = ans.back(); ans.pop_back();
                ans.push_back(-a);
            } else if (i[0] == '-') {
                a = ans.back(); ans.pop_back();
                b = ans.back(); ans.pop_back();
                ans.push_back(b-a);
            }
        }

        return ans.back();

    }
};

signed main() {
    //
}

/*

Polish Notation
O(N*N) time

*/