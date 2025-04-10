#include<bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0); cout.tie(0) ; ios::sync_with_stdio(0);
    int n , m ;
    while(cin >> n >> m ){
        if(n == 0 && n == m ) break;
        vector<vector<int>> left(n+1,vector<int>(m+1,0));
        vector<vector<int>> up(n+1, vector<int>(m+1,0));
        for(int i = 1 ; i <= n ; i++ ){
            for(int j = 1 ; j <= m ; j++ ){
                cin >> left[i][j];
                left[i][j] += left[i][j-1];
            }
        }
        for(int i = 1 ; i <= n ; i++ ){
            for(int j = 1 ; j <= m ; j++ ){
                cin >> up[i][j];
                up[i][j] += up[i-1][j];
            }
        }
        vector<vector<int>> dp(n+1 , vector<int>(m+1,0));
        for(int i = 1 ; i <= n ; i++ ){
            for(int j = 1 ; j <= m ; j++ ){
                dp[i][j] = max(dp[i][j-1] + up[i][j], dp[i-1][j]+left[i][j]);
                // 看這一格要走直的還是橫的
                // 如果走直的，那就是左邊一格的dp配上這一格走直的(整排(包含i,j))
                // 如果走橫的，那就是上面一格的dp配上這一格走行的(整排(包含i,j))
            }
        }
        cout << dp[n][m] << endl;
    }
}