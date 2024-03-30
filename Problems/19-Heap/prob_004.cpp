// BISMILLAH

// Problem link: https://leetcode.com/problems/find-median-from-data-stream/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

class MedianFinder {
public:
    priority_queue<int> first_half, last_half;  // max_heap, min_heap
    int len[2];  // len[0] >= len[1]
    MedianFinder() {
        memset(len,0,sizeof(len));
    }
    
    void addNum(int num) {
        // first insertion
        if (first_half.empty()) {
            first_half.push(num);
            len[0]++;
        } else if (first_half.top() < num) {
            if (len[0] == len[1]) {
                if (num <= -last_half.top()) {
                    first_half.push(num);
                    len[0]++;
                    return;
                } else {
                    // move one val from last to first
                    first_half.push(-last_half.top()); last_half.pop();
                    len[0]++;
                }
            } else {
                assert(len[1] + 1 == len[0]);
                len[1]++;
            }
            last_half.push(-num);
        } else {
            if (len[0] == len[1]) {
                len[0]++;
            } else {
                assert(len[1] + 1 == len[0]);
                // move one val from first to last
                last_half.push(-first_half.top()); first_half.pop();
                len[1]++;
            }
            first_half.push(num);
        }
    }
    
    double findMedian() {
        double ans;
        int fi = first_half.top(), se;
        if (len[0] == len[1]) {
            se = -last_half.top();
            ans = (fi+se)/2.0;
        } else {
            assert(len[1] + 1 == len[0]);
            ans = fi;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

signed main() {
    //
}

/*

"moving median, 2 heap: max, min
abs(size_diff_of_heaps) <= 1"

*/