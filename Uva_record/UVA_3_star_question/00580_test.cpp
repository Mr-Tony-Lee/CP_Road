#include<bits/stdc++.h>
using namespace std;

int main(){
    int number ;
    while(cin >> number , number){
        int dp[3] = {1,1,0};
        for(int i = 2 ; i <= number ; i++ ){
            int lll = dp[0] + dp[1] + dp[2] , llu = dp[0] , luu = dp[1];
            dp[0] = lll , dp[1] = llu , dp[2] = luu;
        }
        cout << (1 << number) - dp[0] - dp[1] - dp[2] <<endl;
    }
}