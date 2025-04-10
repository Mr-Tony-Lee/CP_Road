#include <bits/stdc++.h>
using namespace std;

int all[22][1 << 21]; // 用二維陣列儲存結果

bool iterativeRecur(int* ans, unordered_set<int>& seen, int n) {
    stack<pair<int, int>> stk;  // 使用 stack 避免發生 Stack Overflow (遞迴)
    stk.push({1, ans[0]});  // 初始狀態，從 index = 1 開始
    int mask = (1 << n) - 1; // 限制 n-bit 長度

    while (!stk.empty()) {  
        auto [index, now] = stk.top();
        stk.pop();

        if (index == (1 << n) - n + 1) {
            return true; // 找到完整序列
        }

        int next0 = (now << 1) & mask;    // 左移 + 加 0
        int next1 = ((now << 1) | 1) & mask; // 左移 + 加 1

        // 先處理 "0"，再處理 "1"
        if (!seen.count(next0)) {
            ans[index] = next0; // 如果沒找到，就先放入ans裡面
            seen.insert(next0); // 並insert 進 unordered_set 
            stk.push({index + 1, next0});   // 繼續 stack
            continue;
        }

        if (!seen.count(next1)) {
            ans[index] = next1;
            seen.insert(next1);
            stk.push({index + 1, next1});
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    for (int n = 1 ; n < 22; n++) {
        int size = 1 << n;
        unordered_set<int> seen;    // 此處使用unordered_set 來搜尋，平均時間複雜度是 O(1)
        all[n][0] = 0; // 先處理 ans[0]
        for (int i = 1; i <= n; i++) {  // 先處理 ans[2^n-n]~ans[2^n-1]
            all[n][size - n - 1 + i] = ((1 << n)-1) ^ ((1 << (i-1))-1); 
            seen.insert(all[n][size - n - 1 + i ]);
        }
        seen.insert(all[n][0]); // insert進去 unordered_set
        iterativeRecur(all[n], seen, n); // 使用非遞迴版本
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << all[n][k] << endl; // 直接輸出二進制數值
    }
    return 0 ;
}

// 0011 
// 00 , 01 , 11 ,10 
// 0 , 1 , 3 , 2 
// 00010111
// 000 , 001 , 010 , 101 , 011 , 111 , 110 , 100 
// 0 , 1 , 2 , 5 , 
// 0000100110101111
// 1111 
// 0 , 1 , 2 ,4 , 9 , 3, 6 , 13 , 
// 00000100011001010011101011011111

