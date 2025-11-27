#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    int kase = 0 ; 
    while(cin >> n >> m , (n || m)){
        vector<int> arr1(n) , arr2(m) ;
        for(int i = 0 ; i < n ; ++i ){
            cin >> arr1[i];
        }
        for(int i = 0 ; i < m ; ++i ){
            cin >> arr2[i];
        }
        // LCS -> Longest Common Sequence
        vector<vector<int>> dp (n+1, vector<int>(m+1, 0 ));
        for(int i = 1 ; i <= n ; i++ ){
            for(int j = 1 ; j <= m ; j++ ){
                if(arr1[i-1] == arr2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1 ;
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        cout << "Twin Towers #" << ++kase << endl;
        cout << "Number of Tiles : " << dp[n][m] << endl << endl;
    }
}