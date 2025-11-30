// Leetcode 3759 Count Elements With at Least K Greater Values
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0 ;
        if( k == 0 ) return nums.size();
        for(int i = 0 ; i < nums.size()-k ; i++ ){
            auto iter = upper_bound(nums.begin(),nums.end(), nums[i]);
            if(nums.end() - iter >= k ){
                ans++;
            }
        }
        return ans ;
    }
};
// 77ms, 173.8MB
