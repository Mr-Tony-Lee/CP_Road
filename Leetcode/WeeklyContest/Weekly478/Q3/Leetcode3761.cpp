// 3761. Minimum Absolute Distance Between Mirror Pairs
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long reverse(int a ){
        long long ans = 0 ; 
        while( a > 0  ){
            ans = ans*10 + a % 10 ;
            a /= 10;
        }
        return ans ;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT32_MAX ; 
        int n = nums.size();
        unordered_map<int,vector<int>> pos; // nums[i] -> positions 
        for(int i = 0 ; i < n ; i++ ){
            pos[nums[i]].push_back(i);
        }
        
        for(int i = 0 ; i < n ;i++ ){ 
            int r = reverse(nums[i]);       // find mirror
            auto r_iter = pos.find(r);      // check if mirror exists
            if(r_iter == pos.end()) continue;   // mirror not found
            auto& v = r_iter->second;       // positions of mirror
            auto iter2 = upper_bound(v.begin(), v.end() , i );  // find first position > i
            if(iter2 != v.end()){   // found a valid mirror position
                int d = *iter2 - i ;    // distance
                if( d < ans ) ans = d ;  // update ans
            }
        }
        if(ans == INT32_MAX){
            return -1 ;
        }
        return ans;
    }
};