// 3762. Minimum Operations to Equalize Subarrays
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct ModSegTree { // Segment Tree for min and max of remainders
        int n;
        vector<int> mn, mx;

        // 用遞迴的方式建立 Segment Tree
        void build(int node, int l, int r, const vector<int>& a) {
            if (l == r) {   // leaf node
                mn[node] = mx[node] = a[l];
                return;
            }
            int mid = (l + r) / 2;  
            build(node * 2, l, mid, a); 
            build(node * 2 + 1, mid + 1, r, a);
            mx[node] = max(mx[node * 2], mx[node * 2 + 1]); // 父節點是兩個子節點的 max
            mn[node] = min(mn[node * 2], mn[node * 2 + 1]); // 父節點是兩個子節點的 min
        }
        
        // Segment Tree 大小約為 4*n， n×4 一定會大於總節點數
        void init(const vector<int> &a) {
            n = (int)a.size();
            mn.assign(4 * n, 0);    
            mx.assign(4 * n, 0);    
            build(1, 0, n - 1, a);
        }

        // 查詢區間的最小值和最大值
        pair<int, int> query(int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql) return {INT_MAX, INT_MIN};
            if (ql <= l && r <= qr) return {mn[node], mx[node]};
            // l 左子樹,  r 右子樹
            // ql query left , qr query right
            int mid = (l + r) / 2;
            auto left = query(node * 2, l, mid, ql, qr);
            auto right = query(node * 2 + 1, mid + 1, r, ql, qr);
            return {min(left.first, right.first), max(left.second, right.second)};
        }

        pair<int, int> query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }
    };
    // Merge Sort Tree for counting and summing values <= x in a range
    // Merge Sort Tree 結合了 Segment Tree 和 Merge Sort 的特性
    struct MergeSortTree {
        int n;
        vector<vector<long long>> vals;
        vector<vector<long long>> pref;
        // 建立合併排序樹
        // vals[node] 儲存該節點區間的排序後數值
        // pref[node] 儲存該節點區間的前綴和
        void build(int node, int l, int r, const vector<long long>& a) {
            if (l == r) {
                vals[node] = {a[l]};
                pref[node] = {a[l]};
                return;
            }
            int mid = (l + r) / 2;
            build(node * 2, l, mid, a);
            build(node * 2 + 1, mid + 1, r, a);

            auto &L = vals[node * 2];
            auto &R = vals[node * 2 + 1];
            
            // 合併兩個子區間的排序後數值
            auto &V = vals[node];
            V.resize(L.size() + R.size());

            // 合併兩個已排序的子區間
            merge(L.begin(), L.end(), R.begin(), R.end(), V.begin());

            // 計算前綴和
            auto &P = pref[node];
            P.resize(V.size());
            long long s = 0;
            for (int i = 0; i < (int)V.size(); ++i) {
                s += V[i];
                P[i] = s;
            }
        }

        void init(const vector<long long> &a) {
            n = (int)a.size();
            vals.assign(4 * n, {});
            pref.assign(4 * n, {});
            build(1, 0, n - 1, a);
        }

        // Returns {count of <= x, sum of <= x} in [ql, qr]
        pair<long long, long long> queryLE(int node, int l, int r,
                                           int ql, int qr, long long x) {
            if (qr < l || r < ql) return {0LL, 0LL};
            if (ql <= l && r <= qr) {
                auto &V = vals[node];
                auto &P = pref[node];
                int pos = upper_bound(V.begin(), V.end(), x) - V.begin();
                long long s = (pos > 0 ? P[pos - 1] : 0LL);
                return {(long long)pos, s};
            }
            int mid = (l + r) / 2;
            auto left = queryLE(node * 2, l, mid, ql, qr, x);
            auto right = queryLE(node * 2 + 1, mid + 1, r, ql, qr, x);
            return {left.first + right.first, left.second + right.second};
        }

        pair<long long, long long> queryLE(int l, int r, long long x) {
            return queryLE(1, 0, n - 1, l, r, x);
        }
        
        // Query sum in [ql, qr]
        long long querySum(int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql) return 0LL;
            if (ql <= l && r <= qr) return pref[node].back();
            int mid = (l + r) / 2;
            return querySum(node * 2, l, mid, ql, qr)
                 + querySum(node * 2 + 1, mid + 1, r, ql, qr);
        }

        long long querySum(int l, int r) {
            return querySum(1, 0, n - 1, l, r);
        }
    };

    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = (int)nums.size();
        vector<int> mods(n);    // nums[i] % k
        vector<long long> scaled(n);    // nums[i] / k

        for (int i = 0; i < n; ++i) {
            mods[i] = nums[i] % k;
            scaled[i] = nums[i] / (long long)k;
        }

        ModSegTree modSeg;
        modSeg.init(mods);    // 初始化餘數的區間最小值和最大值查詢結構

        MergeSortTree mst;
        mst.init(scaled);   // 初始化縮放後數值的合併排序樹

        vector<long long> uniq = scaled;
        sort(uniq.begin(), uniq.end());
        uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());

        int Q = (int)queries.size();
        vector<long long> ans(Q);

        for (int qi = 0; qi < Q; ++qi) {
            int l = queries[qi][0];
            int r = queries[qi][1];

            // 1) Feasibility check via remainders
            auto mm = modSeg.query(l, r);
            if (mm.first != mm.second) {    // remainders min != remainders max -> 表示有remainder不同，不可能通過操作變成同一個數
                ans[qi] = -1;
                continue;
            }

            // 2) If feasible, work in scaled space
            int len = r - l + 1;
            long long totalSum = mst.querySum(l, r);
            int K = (len + 1) / 2;  // median rank

            // Binary search on uniq[] to find median value
            int lo = 0, hi = (int)uniq.size() - 1;
            int bestIdx = hi;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                long long x = uniq[mid];
                auto le = mst.queryLE(l, r, x);
                long long cntLE = le.first;
                if (cntLE >= K) {
                    bestIdx = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            long long med = uniq[bestIdx];

            // Compute sum |scaled[i] - med| over [l, r]
            auto le = mst.queryLE(l, r, med);
            long long cntLE = le.first;
            long long sumLE = le.second;

            long long lenLL = (long long)len;

            long long greaterCnt = lenLL - cntLE;
            long long sumGreater = totalSum - sumLE;

            long long cost =
                med * cntLE - sumLE +
                sumGreater - med * greaterCnt;

            ans[qi] = cost;
        }

        return ans;
    }
};
// 1570ms, 541.36MB