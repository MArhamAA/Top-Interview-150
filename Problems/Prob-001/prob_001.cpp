// BISMILLAH

#include <bits/stdc++.h>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            nums1 = nums2;
            return;
        }

        std::vector<int> ans(n+m);
        int i = 0, j = 0, idx=0;

        while (i < m || j < n) {
            if (i == m) {
                ans[idx++] = nums2[j++];
            } else if (j == n) {
                ans[idx++] = nums1[i++];
            } else if (nums1[i] <= nums2[j]) {
                ans[idx++] = nums1[i++];
            } else {
                ans[idx++] = nums2[j++];
            }
        }

        nums1 = ans;
    }

signed main() {
	int testCases=1;
	scanf("%d",&testCases);
	
	for (int T = 1; T <= testCases; T++) {
        int m, n;
        scanf("%d", &m);
        std::vector<int> a(m);
        for (auto &i : a)
            scanf("%d", &i);

        scanf("%d", &n);
        std::vector<int> b(n);
        for (auto &i : b)
            scanf("%d", &i);

        for (int i = 0; i < n; i++)
            a.push_back(0);

        merge(a, m, b, n);
        for (auto i : a)
            printf("%d ", i);
        printf("\n");
    }
	
	return 0;
}

/*

https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

Basic merge algo. T&M: O(N)

*/