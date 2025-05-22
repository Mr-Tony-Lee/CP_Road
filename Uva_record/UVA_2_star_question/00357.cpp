#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    vector<int> dp(30001,0);
    int coin[5] = {1,5,10,25,50};
    dp[0] = 1 ;
    for(int i = 0 ; i < 5 ; i++ ){
        for(int j = coin[i] ; j <= 30000 ; j++ ){
            dp[j] += dp[j-coin[i]];
        }
    }
    int n ;
    while(cin >> n ){
        if( n < 5 ){
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        }
        else{
            cout << "There are " << dp[n] << " ways to produce "<< n << " cents change."<< endl;
        }
    }   
}