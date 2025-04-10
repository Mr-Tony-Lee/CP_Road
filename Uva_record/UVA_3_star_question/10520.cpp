#include<bits/stdc++.h>
using namespace std;
#define int long long 

int solve(vector<vector<int>>& dp,int i , int n , int j ){
    if( i >= j ){
        int max_k = 0 ;
        if( i < n ){
            for(int k = i+1 ; k <= n ; k++ ){
                max_k = max(max_k,dp[k][1]+dp[k][j]);
            }
        }
        int max_jk = 0 ;
        if( j > 0 ){
            for(int k = 1 ; k < j ; k++ ){
                max_jk = max(max_jk,dp[i][k]+dp[n][k]);
            }
        }    
        return max_k + max_jk ;
    }
    else{
        int max_k = 0 ; 
        for(int k = i ; k < j ; k++ ){
            max_k = max(max_k , dp[i][k]+dp[k+1][j]);
        }
        return max_k;
    }
}

int32_t main(){
    int n , an1 ; 
    while( cin >> n >> an1 ){
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        dp[n][1] = an1;
        for(int z = n ; z >= 1 ; z-- ){
            for(int j = 1 ; j <= z ; j++ ){
                if( z == n && j == 1 ) continue;
                dp[z][j] = solve(dp, z , n , j );
                // cout << "i = " << z << ",j = " << j << " " << dp[n][j] << endl;
            }   
        }
        
        for(int j = 2 ; j <= n ; j++ ){
            dp[1][j] = solve(dp,1,n,j);
        }
        
        cout << dp[1][n] << endl;
    }
}
// 已知 a[n][1] -> 可知 a[n][2] ... -> a[n][n]
// 透過a[n][1] 可知 a[n-1][1] -> 可知 a[n-1][2] ... -> a[n-1][n-1];
// 最後可以知道整個上三角 (矩陣的上三角)
// 那dp[1][1] 會在最後知道 ， 知道dp[1][1]就可以知道dp[1][2] ... 最後知道 dp[1][n] 
// Online Judge Accepted.