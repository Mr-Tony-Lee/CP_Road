#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 樹狀數組 (Binary Indexed Tree)
    // BIT 存放的是頻率 (frequency)
    // Ex: BIT.sum(k) 回傳的是前 k 項的頻率總和
    // Ex: BIT.upd(k, v) 將第 k 項的頻率增加 v
    // 第 `i` 個位置存儲數值 `i` 在當前窗口中出現的次數
    struct BIT {
        int n;
        vector<int> bit;
        BIT() {}
        BIT(int _n) {
            n = _n;
            bit = vector<int>(n + 1, 0);
        }
        // 更新 BIT 的值    
        void upd(int k, int v) {
            while(k <= n) {
                bit[k] += v;    
                k += k & -k;    // 對應到下一個包含 k 的區間
            }
        }

        // 利用 BIT 計算前 k 項的和
        int sum(int k) {
            int s = 0;
            while(k > 0) {
                s += bit[k];
                k -= k & -k;    // 對應到上一個區間 -> Ex: [1:8] + [9:12] + [13:13] -> [1:13] 
            }
            return s;
        }
    };

    struct SLIDING_WINDOW {
        long long inv_count;
        deque<int> window;
        int m;  // max number after coordinate compression
        BIT B;
        
        SLIDING_WINDOW(int _m) {
            inv_count = 0;
            m = _m;
            B = BIT(m);
        }
        
        void expand(int x) {
            // 增加逆序對：比 x 大的數的個數
            // inversion count = 大於 x 的數的個數 = 當前總數 - 小於等於 x 的數的個數
            inv_count += B.sum(m) - B.sum(x);
            
            window.push_back(x);
            B.upd(x, +1);
        }
        
        void shrink() {
            int x = window.front();
            // 減少逆序對：比 x 小的數的個數
            // = 小於等於 x-1 的數的個數
            inv_count -= B.sum(x - 1);
            
            window.pop_front();
            B.upd(x, -1);
        }
    };

    long long minInversionCount(vector<int>& nums, int k) {
        int n = (int)nums.size();

        // 1. 離散化 (Coordinate Compression)
        set<int> S;
        for(auto x : nums) {
            S.insert(x);
        }
        int m = 1;
        map<int, int> convert;
        for(auto x : S) {
            convert[x] = m++;
        }
        for(auto &x : nums) {
            x = convert[x];
        }
        
        // 2. 滑動窗口 + BIT
        SLIDING_WINDOW SW(m);
        
        // 初始化第一個窗口
        for(int i = 0; i < k; i ++) SW.expand(nums[i]);
        
        long long ans = SW.inv_count;
        
        // 開始滑動
        for(int i = k; i < n; i ++){
            SW.shrink();
            SW.expand(nums[i]);
            ans = min(ans, SW.inv_count);
        }
        return ans;
    }
};