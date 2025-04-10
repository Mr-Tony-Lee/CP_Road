#include<bits/stdc++.h>
using namespace std;

int main(){
    int dp[51] = {};
    dp[1] = 1 ;
    dp[2] = 2 ; 
    for(int i = 3 ; i <= 50 ; i++ ){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int n ;
    while(cin >> n , n ){
        cout << dp[n] << endl;
    }
}
// dp[i] = dp[i-1](補一根直的) + dp[i-2](補兩根橫的) , 