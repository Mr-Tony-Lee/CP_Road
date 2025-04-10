#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    int dp[77];
    dp[1] = 1 ; dp[2] = 2 ;dp[3] = 2 ;
    for(int i = 4 ; i <= 76 ; i++ )     dp[i] = dp[i-2]+dp[i-3];
    while(cin >> n )    cout << dp[n] << endl;
}
/*
    放 1 的分支可以放 3~5 也就等同於 n=3 的情況
    放 2 的分支可以放 4~5 相當於 n=2 的情況
    所以說 n=5 就是 n=2 的解 + n=3 的解
*/