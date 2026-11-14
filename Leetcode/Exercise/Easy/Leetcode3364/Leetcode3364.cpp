#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pref(n+1, 0);
        for(int i = 1 ; i <= n ; i++ ){
            pref[i] = pref[i-1] + nums[i-1];
        }
        // pref[i] : prefix sum from index 0 ~ i-1
        int ans = INT_MAX ; 
        for(int k = l ; k <= r ; k++ ){
            for(int i = 1 ; i <= n-k+1 ; i++ ){
                int temp = pref[i+k-1] - pref[i-1];
                if( temp > 0 ){
                    ans = min(temp , ans);
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};