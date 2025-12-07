#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long BitReverse (int n ){
        long long ans =0 ; 
        while( n > 0 ){
            ans = (ans << 1) + (n & 1) ;
            n >>= 1 ;
        }
        return ans ;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int, int>> store;  
        for (int x : nums) {
            store.push_back({BitReverse(x), x});
        }  
        sort(store.begin(), store.end());
        vector<int> res;
        for(int i = 0;i < store.size();i++) {
            res.push_back(store[i].second);
        } 
        return res;
    }
};