#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int prev = 0 ;
        int cnt = 1 ; 
        long long ans = 0 ; 
        for(auto& p : prices){
            if(prev != 0 ){
                if( prev-p == 1 ){
                    cnt++;
                }
                else{
                    ans += 1LL*(cnt)*(cnt+1)/2;
                    cnt = 1 ;
                }
            }
            prev = p ;
        }
        ans += 1LL*(cnt)*(cnt+1)/2;
        return ans ;
    }
};