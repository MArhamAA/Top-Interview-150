// BISMILLAH

#include <bits/stdc++.h>

int jump(std::vector<int>& nums) {
    int N = (int)nums.size(), cur, lo, hi, mi, pos;
    std::vector<int> path;
    path.push_back(N-1);
    int siz = 1;

    for (int i = N-2; i >= 0; i--) {
        cur = nums[i] + i;
        lo = 0, hi = siz-1;
        pos = -1;
        while (lo <= hi) {
            mi = lo + (hi-lo)/2;
            if (path[mi] > cur) {
                lo = mi+1;
            } else {
                pos = mi;
                hi = mi-1;
            }
        }

        if (pos != -1) {
            while (siz-1 > pos) {
                path.pop_back();
                siz--;
            }
            path.push_back(i);
            siz++;
        }
    }

    return siz-1;
}

signed main() {
	//
}

/*

https://leetcode.com/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150

O(N lgN) time

"Iteration from the end and binary search. 
I maintain a stack of reachable indices. 
If any index can overcome some positions 
in stack and reach a position in stack then 
delete those overcomed indices and insert 
new index to the stack. 
Return stack.size() - 1 as ans."

*/