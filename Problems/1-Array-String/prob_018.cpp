// BISMILLAH

#include "bits/stdc++.h"

std::string hash(int val) {
    std::string res;
    switch(val) {
        case 1000:
            res = "M";
            break;
        case 900:
            res = "CM";
            break;
        case 500:
            res = "D";
            break;
        case 400:
            res = "CD";
            break;
        case 100:
            res = "C";
            break;
        case 90:
            res = "XC";
            break;
        case 50:
            res = "L";
            break;
        case 40:
            res = "XL";
            break;
        case 10:
            res = "X";
            break;
        case 9:
            res = "IX";
            break;
        case 5:
            res = "V";
            break;
        case 4:
            res = "IV";
            break;
        case 1:
            res = "I";
            break;
    }
    return res;
}
std::string intToRoman(int num) {
    int a[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string ans;

    for (int i : a) {
        int pos = num/i;
        num %= i;
        while (pos--) {
            ans += hash(i);
        }
    }

    return ans;
}

signed main() {
    //
}

/*

https://leetcode.com/problems/integer-to-roman/description/?envType=study-plan-v2&envId=top-interview-150

Implementation

*/