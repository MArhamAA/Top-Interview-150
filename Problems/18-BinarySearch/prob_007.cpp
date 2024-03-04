// BISMILLAH

// Problem link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // both lower_bound and upper_bound are required?
        int N = (int)nums1.size()-1;
        int M = (int)nums2.size()-1;
        int tot = N+M+2;
        int req = (tot&1) ? (tot-1)/2 : (tot-2)/2;
        int L, R; L = R = INT_MIN;

        auto low = [] (int v, std::vector<int>& a) {
            int mi, lo = 0, hi = (int)a.size()-1, tot=0;
            while (lo <= hi) {
                mi = lo+(hi-lo)/2;
                if (a[mi] < v) {
                    tot = mi+1;
                    lo = mi+1;
                } else {
                    hi = mi-1;
                }
            }
            return tot;
        };
        auto high = [] (int v, std::vector<int>& a) {
            int mi, lo = 0, hi = (int)a.size()-1, tot=0;
            while (lo <= hi) {
                mi = lo+(hi-lo)/2;
                if (v < a[mi]) {
                    tot = (int)a.size()-mi;
                    hi = mi-1;
                } else {
                    lo = mi+1;
                }
            }
            return tot;
        };

        // L calc
        int lo = 0, hi = N, mi;
        while (lo <= hi) {
            mi = lo+(hi-lo)/2;
            int cur = nums1[mi];
            int chuto = low(cur, nums1) + low(cur, nums2);
            int boro = high(cur, nums1) + high(cur, nums2);
            int self_range = (N+M+2)-(chuto+boro);
            if (chuto <= req && chuto+self_range > req) {
                L = nums1[mi];
                break;
            }
            if (chuto < req) {
                lo = mi+1;
            } else {
                hi = mi-1;
            }
        }
        lo = 0, hi = M;
        while (lo <= hi) {
            mi = lo+(hi-lo)/2;
            int cur = nums2[mi];
            int chuto = low(cur, nums1) + low(cur, nums2);
            int boro = high(cur, nums1) + high(cur, nums2);
            int self_range = (N+M+2)-(chuto+boro);
            if (chuto <= req && chuto+self_range > req) {
                L = nums2[mi];
                break;
            }
            if (chuto < req) {
                lo = mi+1;
            } else {
                hi = mi-1;
            }
        }
        printf("L: %d\n",L);

        // R calc
        lo = 0, hi = N;
        while (lo <= hi) {
            mi = lo+(hi-lo)/2;
            int cur = nums1[mi];
            int chuto = low(cur, nums1) + low(cur, nums2);
            int boro = high(cur, nums1) + high(cur, nums2);
            int self_range = (N+M+2)-(chuto+boro);
            if (boro <= req && boro+self_range > req) {
                R = nums1[mi];
                break;
            }
            if (boro < req) {
                hi = mi-1;
            } else {
                lo = mi+1;
            }
        }
        lo = 0, hi = M;
        while (lo <= hi) {
            mi = lo+(hi-lo)/2;
            int cur = nums2[mi];
            int chuto = low(cur, nums1) + low(cur, nums2);
            int boro = high(cur, nums1) + high(cur, nums2);
            int self_range = (N+M+2)-(chuto+boro);
            if (boro <= req && boro+self_range > req) {
                R = nums2[mi];
                break;
            }
            if (boro < req) {
                hi = mi-1;
            } else {
                lo = mi+1;
            }
        }
        printf("R: %d\n",R);
        return (L+R)/2.0;
    }
};

signed main() {
    //
}

/*

"low, high value count, binary search on 
both array idx, observation"

*/