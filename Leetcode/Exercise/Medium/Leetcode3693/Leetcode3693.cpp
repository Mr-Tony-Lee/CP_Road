#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        // memory optimize
        int dp_0 = 0, dp_1 = cost[0]+1;
        if( n == 1 ) return dp_1;
        int dp_2 = cost[1] + min(dp_0+4, dp_1+1);
        if( n == 2 ) return dp_2;
        for(int i = 3 ; i <= n ; i++ ){
            int dp = cost[i-1] + min({dp_0+9, dp_1+4, dp_2+1});
            dp_0 = dp_1; dp_1 = dp_2 ; dp_2 = dp;
        }
        return dp_2;
    }
};