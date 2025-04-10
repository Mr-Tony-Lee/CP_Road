#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1, 0 ,-1};

int dfs(vector<vector<int>>& arr , int now_x , int now_y , vector<vector<int>>& dp , int r , int c ){
    if(dp[now_x][now_y] != -1 ) return dp[now_x][now_y];
    
    dp[now_x][now_y] = 1 ;  // 進來先存1，一定有1步

    for(int i = 0 ; i < 4 ; i++){
        int nx = now_x + dx[i];
        int ny = now_y + dy[i];
        if( nx >= 0 && nx < r && ny >= 0 && ny < c  ){
            if(arr[nx][ny] < arr[now_x][now_y]){
                dp[now_x][now_y] = max(dp[now_x][now_y], 1 + dfs(arr,nx,ny,dp,r,c));    // 四個方向的走法裡面最大的
            }
        }
        
    }
    return dp[now_x][now_y];
}

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int t ;
    cin >> t ;
    while(t--){
        string input ;
        int r , c ;
        cin >> input >> r >> c; 
        int ans = 0 ; 
        vector<vector<int>> arr(r,vector<int>(c,0));
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++ ){
                  cin >> arr[i][j] ;
            }
        }
        vector<vector<int>> dp(105, vector<int>(105,-1));   // 使用dp緩存已經走過的格子
        for(int i = 0 ; i < r ; i++ ){
            for(int j = 0 ; j < c ; j++ ){
                int tmp  = dfs(arr, i ,j , dp , r , c );
                ans = max(tmp,ans);
            }
        }
        cout << input << ": " << ans << endl;
    }
}