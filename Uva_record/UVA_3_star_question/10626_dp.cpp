#include<bits/stdc++.h>
using namespace std;

int dp[1000][200][110];
int solve(int c ,int n1 , int n5 , int n10){
    if(c == 0 ) return 0;
    int & ans = dp[n1][n5][n10];
    if( ans != 0 ) return ans;

    ans = 1 << 30;
    if(n10 >= 1 ){
        ans = min(ans,solve(c-1 , n1+2,n5,n10-1)+1);
    }
    if(n10 >= 1 && n1 >= 3 ){
        ans = min(ans,solve(c-1 , n1-3,n5+1,n10-1)+4);
    }
    if( n5 >= 2 ){
        ans = min(ans,solve(c-1 , n1+2,n5-2,n10)+2);
    }
    if( n1 >= 3 && n5 >= 1 ){
        ans = min(ans,solve(c-1 , n1-3,n5-1,n10)+4);
    }
    if( n1 >= 8 ){
        ans = min(ans,solve(c-1 , n1-8, n5, n10)+8);
    }
    return ans ; 
}

int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);
    int t ;
    cin >> t ;
    while(t--){
        memset(dp,0,sizeof(dp));
        int c , n1 , n5 , n10 ;
        cin >> c >> n1 >> n5 >> n10;
        cout << solve(c,n1,n5,n10) << endl;
    }
}