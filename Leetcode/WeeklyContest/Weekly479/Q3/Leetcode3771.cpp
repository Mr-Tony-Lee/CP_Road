#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int N = damage.size();
        long long ans = 0 ; 
        vector<int> pref(N+1,0);
        for(int i = 1 ; i <= N ; i++ ){
            pref[i] = pref[i-1] + damage[i-1];
        }
        for(int i = 1 ; i <= N ; i++ ){
            long long T = (long long)requirement[i-1] - hp + pref[i];
            int l = 0 , r = N ;
            while( l < r ){
                int mid = l + ( r - l ) / 2 ;
                if( pref[mid] >= T )
                    r = mid ;
                else
                    l = mid + 1 ;
            }
            if(l <= i-1 ) 
                ans += ( i - l ) ;
        }
        return ans ;
    }
};