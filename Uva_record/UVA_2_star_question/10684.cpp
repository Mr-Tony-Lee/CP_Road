#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    int N ;
    while(cin >> N , N ){
        int dp[N][1] = {};
        // dp[i][j] 表示第 i 項在兩種情況中前i項的連續最大和
        // j = 0 表示第 i 項已包含在已存在的連續序列當中，-> dp[i][0] = arr[k~i] , k = 0~i 之間的某個數
        // j = 1 表示第 i 項為新的連續序列開頭 -> dp[i][1] = arr[i]
        // dp[i][0] 會是前一項較大的數列(dp[i-1][0] or dp[i-1][1]) + 現在的值 -> max(dp[i-1][0],dp[i-1][1]) + num 
        // 然後數列的最大值會出現在其中
        int ans = 0 ; 
        for(int i = 0 ; i < N ; i++ ){
            int num ;
            cin >> num ;
            if( i == 0 ){
                dp[i][1] = num ;
                dp[i][0] = 0 ;
            }
            else{
                dp[i][0] = max(dp[i-1][0],dp[i-1][1]) + num ;
                dp[i][1] = num ;
            }
            ans = max(ans,max(dp[i][0],dp[i][1]));
        }
        if(!ans){
            cout << "Losing streak." << endl;
        }
        else{
            cout << "The maximum winning streak is " << ans << "." << endl;
        }
    }
}