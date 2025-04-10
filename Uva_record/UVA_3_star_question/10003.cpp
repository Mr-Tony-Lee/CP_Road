#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(false);
    int l ;
    while( cin >> l , l ){
        int n ; 
        cin >> n ;
        vector<int> cut(n+2);   // 每次切割的點 
        for(int i = 1 ; i <= n ; i++ ){
            cin >> cut[i] ; 
        }
        cut[0] = 0 ; 
        cut[n+1] = l ;  
        int dp[n+2][n+2]; 
        memset(dp, 0 , sizeof(dp)); // 一開始設為0 (為了方便之後dp[i][j] = 0 if j - i <= 1 )
        for(int r = 2 ; r <= n+1 ; r++ ){ // 本次要切割的區間大小 ( 那不會小於2 ， 不會大於 n+1 )
            for(int b = 0 ; b < n ; b++ ){  // 左區間，從0 ~ n+1-2 = 0 ~ n-1 
                int e = b + r ; // 右邊的區間， 就是左邊的區間 + 這次要切割的區間大小
                if( e > n+1 ) break;  // 如果右邊的區間大於 n+1 就結束
                dp[b][e] = INT_MAX;
                for(int c = b+1 ; c < e ; c++ ){
                    int temp = dp[b][c] + dp[c][e] + cut[e] - cut[b];  // 這是本次cut的cost
                    dp[b][e] = min(temp , dp[b][e]);
                }
            }
        }    
        int ans = dp[0][n+1] ;
        cout << "The minimum cutting is " << ans << "." << endl;
    }
}

// 假設 現在 wood 0---2---4---7---10 
// 然後我 dp[i][j] 就是 切割點 i ~ j 的最低成本
// 那我選擇在 cut == 2 的地方切割
// 那本次的切割 dp[0][1] + dp[1][4] + (cut[4] - cut[0] = 10)
// 那 dp[1][4] 就是下一次切割的成本 假設下一刀切在cut == 4 
// 那本次切割就是 dp[1][2] + dp[2][4] + (cut[4] - cut[1] = 8 )
// 那 dp[2][4] 就是最後一刀 7 的切割成本 ， 我們知道下一刀在7 
// dp[2][3] + dp[3][4] + (cut[4]-cut[2] = 6 ) // 那dp[2][3] 跟 dp[3][4] 因為只相差 1 是 0 
// 所以最後就是 dp[2][4] = 6 , dp[1][4] = 0+6+8 = 14 , dp[0][4] = 0 + 14 + 10 = 24 
// 那知道了過程，之後就是在每次 dp 取 min 找最小的拿