#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        int sum = 0; 
        for(int i = 0 ; i < n ; i++ ){
            sum += nums[i];
            pref[i] = sum ;
        }
        int ans = 0 ;
        for(int i = 0 ; i < n-1 ; i++){
            if(abs(sum - 2*pref[i]) % 2 == 0 ){
                ans++;
            }
        }
        return ans ;
    }
};
// 0ms, 23.01MB

/*
Better solution, since we check abs(sum-2*pref[i]) % 2 == 0
We can just check sum % 2 == 0
and return (n-1) * (sum % 2 == 0);
*/