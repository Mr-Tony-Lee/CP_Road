#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mmin = INT_MAX, ans = 0 ; 
        for(int i = 0 ; i < nums.size()-2 ; i++ ){
            int left = i+1 ; 
            int right = nums.size()-1;
            while( left < right ){
                int sum = nums[i] + nums[left] + nums[right];
                if( sum == target ){
                    return target;
                }
                else if (sum < target){
                    if(abs(sum-target) < mmin ){
                        mmin = abs(sum-target);
                        ans = sum;  
                    }
                    left++;
                }
                else{
                    if(abs(sum-target) < mmin ){
                        mmin = abs(sum-target);
                        ans = sum;  
                    }
                    right--;
                }
            } 
        }
        return ans;      
    }
};
// 4ms , 14 MB