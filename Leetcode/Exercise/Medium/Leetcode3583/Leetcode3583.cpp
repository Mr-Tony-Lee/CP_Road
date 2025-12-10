#include <bits/stdc++.h>
using namespace std;

// method 1 
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int> totalCnt;
        unordered_map<int,int> leftCnt ;
        totalCnt.reserve(nums.size()*2);
        leftCnt.reserve(nums.size()*2);

        const int mod = 1e9+7;
        long long ans = 0 ;
        
        for(auto& num:nums ){
            totalCnt[num] ++;
        }
        
        for(auto& num:nums){
            int target = num*2;
            int Lcnt = leftCnt[target];
            leftCnt[num]++;

            int Rcnt = totalCnt[target]-leftCnt[target];
            ans += (1LL * Lcnt  * Rcnt) % mod;
            ans %= mod;
        }
        return ans ;
    }
};

// method 2
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,vector<int>> arr;
        arr.reserve(nums.size()*2);
        const int mod = 1e9+7;
        long long ans = 0 ;
        for(int i = 0 ; i < nums.size(); i++ ){
            arr[nums[i]].push_back(i);
        }
        for(int i = 1 ; i < nums.size()-1; i++){
            int target = nums[i]*2;
            const auto& choice= arr[target];
            int low = 0 , high = 0 ;
            if(choice.size() != 0 ){
                high = choice.end() - upper_bound(choice.begin(), choice.end() , i);
                // 0 1 0 0
                // arr[0] -> {0,2,3}
                low = choice.size() - high;
            }
            if(target == nums[i]){
                low -= 1 ;
            }
            ans += (1LL*low * high) % mod;
            ans %= mod;
        }
        return ans ;
    }
};