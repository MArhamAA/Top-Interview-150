// BISMILLAH

// Problem link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/?envType=study-plan-v2&envId=top-interview-150

#include "bits/stdc++.h"
using namespace std;

using pii = pair<int,int>;
using ppii = pair<int,pii>;
using pp = pair<pii,pii>;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int N = (int)nums1.size();
        int M = (int)nums2.size();
        int MX = max(N, M);

        int ID[2][MX];  // next idx of opposite array
        memset(ID, 0, sizeof(ID));

        map<pii, bool> used;  // already paired idx
        
        vector<vector<int>> ans;
        multiset<ppii> sorted;  // min Heap
        multiset<pp> best;  // min Heap
        ppii cur;
        pp bcur;
        int val, onno_val, idx, onno_idx, which;
        
        for (int i = 0; i < N; i++) sorted.insert(ppii(nums1[i], pii(i, 0)));
        for (int i = 0; i < M; i++) sorted.insert(ppii(nums2[i], pii(i, 1)));

        while ((int)ans.size() < k) {
            // puts("best:");
            // for (auto i : best) printf("s:%d i:%d ov:%d w:%d\n",i.first.first,i.first.second,i.second.first,i.second.second);
            if ((int)best.size() == 0) {
                // puts("first insertion:");
                cur = *sorted.begin(); sorted.erase(sorted.begin());
                val = cur.first, idx = cur.second.first, which = cur.second.second;
                onno_idx = ID[which][idx];
                onno_val = (which == 0) ? nums2[onno_idx] : nums1[onno_idx];
                bcur.first = pii(val + onno_val, idx);
                bcur.second = pii(onno_val, which);
                ID[which][idx]++;
                // ID[1-which][onno_idx]++;
                if (which) used[pii(onno_idx, idx)] = 1;
                else used[pii(idx,onno_idx)] = 1;
                best.insert(bcur);
                // printf("best: s:%d v:%d i:%d ov:%d w:%d\n", bcur.first.first,val,bcur.first.second,bcur.second.first,bcur.second.second);
                continue;
            }

            assert((int)best.size());
            bcur = *best.begin(); best.erase(best.begin());
            idx = bcur.first.second;
            onno_val = bcur.second.first;
            which = bcur.second.second;
            val = (which == 0) ? nums1[idx] : nums2[idx];
            // printf("working: v:%d i:%d ov:%d w:%d\n",val,idx,onno_val,which);

            if (which == 0) {
                ans.push_back({val, onno_val});
            } else {
                ans.push_back({onno_val, val});
            }

            // insert new item? for val
            if (which == 0 && ID[which][idx] < M) {
                onno_idx = ID[which][idx];
                if (used.find(pii(idx, onno_idx)) == used.end()) {
                    onno_val = (which == 0) ? nums2[onno_idx] : nums1[onno_idx];
                    bcur.first.first = val+onno_val;
                    bcur.second.first = onno_val;
                    ID[which][idx]++;
                    // ID[1-which][onno_idx]++;
                    best.insert(bcur);
                    used[pii(idx,onno_idx)] = 1;
                    // puts("new insertion of val:");
                    // printf("best: s:%d v:%d i:%d ov:%d w:%d\n", bcur.first.first,val,bcur.first.second,bcur.second.first,bcur.second.second);
                }
            } else if (which && ID[which][idx] < N) {
                onno_idx = ID[which][idx];
                if (used.find(pii(onno_idx,idx)) == used.end()) {
                    onno_val = (which == 0) ? nums2[onno_idx] : nums1[onno_idx];
                    bcur.first.first = val+onno_val;
                    bcur.second.first = onno_val;
                    ID[which][idx]++;
                    // ID[1-which][onno_idx]++;
                    best.insert(bcur);
                    used[pii(onno_idx,idx)] = 1;
                    // puts("new insertion of val:");
                    // printf("best: s:%d v:%d i:%d ov:%d w:%d\n", bcur.first.first,val,bcur.first.second,bcur.second.first,bcur.second.second);
                }
            }

            // new min item?
            while ((int)sorted.size()) {
                // puts("new min insertion:");
                cur = *sorted.begin(); sorted.erase(sorted.begin());
                val = cur.first, idx = cur.second.first, which = cur.second.second;
                onno_idx = ID[which][idx];
                if (which == 0) {
                    if (onno_idx == M) continue;
                    if (used.find(pii(idx,onno_idx)) != used.end()) continue;
                } else {
                    if (onno_idx == N) continue;
                    if (used.find(pii(onno_idx,idx)) != used.end()) continue;
                }
                onno_val = (which == 0) ? nums2[onno_idx] : nums1[onno_idx];
                bcur.first = pii(val+onno_val, idx);
                bcur.second = pii(onno_val, which);
                ID[which][idx]++;
                // ID[1-which][onno_idx]++;
                if (which) used[pii(onno_idx, idx)] = 1;
                else used[pii(idx,onno_idx)] = 1;
                // if (which == 0 && onno_val == 7) printf("%d %d\n",ID[which][idx],ID[1-which][onno_idx]);
                best.insert(bcur);
                // printf("best: s:%d v:%d i:%d ov:%d w:%d\n", bcur.first.first,val,bcur.first.second,bcur.second.first,bcur.second.second);
                break;
            }

        }

        sort(ans.begin(), ans.end(), [] (vector<int> fi, vector<int> se){
            int fi_sum = fi[0] + fi[1];
            int se_sum = se[0] + se[1];
            if (fi_sum == se_sum) {
                if (fi[0] == se[0]) return fi[1] < se[1];
                return fi[0] < se[0];
            }
            return fi_sum < se_sum;
        });
        return ans;
    }
};

signed main() {
    //
}

/*

"min_heap, hashmap, greedy;
maintain next takable idx for each val;
update opposite val? for current val;
add new minimum item from min_heap"

implementation

*/