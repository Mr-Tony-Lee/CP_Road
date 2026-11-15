#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int prev_res = 0, ans = 0; 
        // 作法: 跑到 idx i 時，往回看 i-1 ~ i , i-2 ~ i ... 0 ~ i 的 odd 數量有幾個
        // 因 i-1 ~ i-1 , i-2 ~ i-1 , ... , 0 ~ i-1 已經算過了，用 prev_res 來儲存
        // 若 arr[i] 是 odd，那我就去看 i-1 ~ i-1 , i-2 ~ i-1 , ... , 0 ~ i-1 有幾個 even 再加上 1 (arr[i])
        // even 的數量就是 i - prev_res
        // 若 arr[i] 是 even，那就直接找之前有幾個 odd, i.e prev_res
        for(int i = 0 ; i < arr.size() ; i++ ){
            prev_res = (arr[i] & 1 ) ? i - prev_res + 1 : prev_res;
            ans += prev_res;
            ans %= mod;
        }        
        return ans;
    }
};