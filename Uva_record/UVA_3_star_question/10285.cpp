#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1, 0 ,-1};

int dfs(vector<vector<int>> arr , int now_x , int now_y , vector<vector<bool>> visit , int ans , int r , int c ){
    int max_s = 0 ;
    visit[now_x][now_y] = true;
    for(int i = 0 ; i < 4 ; i++){
        int step = 1 ;
        int nx = now_x + dx[i];
        int ny = now_y + dy[i];
        if( nx >= 0 && nx < r && ny >= 0 && ny < c  ){
            if(arr[nx][ny] < arr[now_x][now_y]){
                step += dfs(arr,nx,ny,visit,ans,r,c);
            }
        }
        max_s = max(max_s, step);
    }
    return max_s;
}

int main(){
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
        for(int i = 0 ; i < r ; i++ ){
            for(int j = 0 ; j < c ; j++ ){
                vector<vector<bool>> visit(r,vector<bool>(c,false));
                int tmp  = dfs(arr, i ,j , visit , ans , r , c );
                ans = max(tmp,ans);
            }
        }
        cout << input << ": " << ans << endl;
    }
}
// Accepted Online judge.