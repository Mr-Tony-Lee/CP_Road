#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    int n ;
    vector<vector<int>> dp(1001,vector<int>(3000,0));
    dp[0][0] = 1 ;
    dp[1][0] = 2 ;
    dp[2][0] = 3 ;
    vector<int> size(1001,1);
    for(int i = 3 ; i <= 1000 ; i++ ){
        // dp[i] = dp[i-2]*2 + (dp[i-1]-dp[i-2]); // 經過兩條線的下次必定會出兩種組合，而只有一條的就只有一種，所以我們要找出前一項經過兩條線的，找規律發現，
        // a1 的時候有1條(a0的總條數)，a2有2條(a1的總條數)，a3有3條(a2的總條數)...，所以也就是 dp[i-2] * 2 + (dp[i-1]-dp[i-2])(最後要加上只經過1條線的，也就是上次轉彎是在中間那條線的)
        // dp[i] = dp[i-2]+dp[i-1]; // 化簡
        // 大數運算
        int carry = 0 ; 
        for(int j = 0 ; j < size[i-1] ; j++ ){
            dp[i][j] = dp[i-1][j] + dp[i-2][j] + carry;
            carry = dp[i][j] / 10 ;
            dp[i][j] %= 10 ;
        }
        size[i] = size[i-1];
        if(carry){
            dp[i][size[i-1]] = 1 ;
            size[i]++;
        }
    }
    while(cin >> n ){
        for(int i = size[n]-1 ; i >= 0 ;i--){
            cout << dp[n][i] ;
        }
        cout << endl;
    }
}