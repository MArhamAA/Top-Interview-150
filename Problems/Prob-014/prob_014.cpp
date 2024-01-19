// BISMILLAH

#include <bits/stdc++.h>

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    int N = (int)gas.size();
    int a[2*N-1], ans = 0;

    for (int i = 0; i < N; i++) {
        a[i] = gas[i] - cost[i];
    }
    for (int i = N; i < 2*N-1; i++) {
        a[i] = a[i-N];
    }

    int cur_sum = 0;
    for (int i = 0; i < 2*N-1; i++) {
        cur_sum += a[i];
        while (cur_sum < 0) {
            cur_sum -= a[ans++];
        }
    }

    if (ans >= N || a[ans] < 0) ans = -1;

    return ans;
}

signed main() {
	//
}

/*

https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150

Two Pointers, cyclic iteration over array

*/