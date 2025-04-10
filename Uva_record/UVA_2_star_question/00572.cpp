#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int m , n ;
    while( (cin >> m >> n ) && m ){
        char array[m][n] = {};
        int ans = 0 ; 
        for(int i = 0 ; i < m ; i++ ){
            for(int j = 0 ; j < n ; j++ ){
                cin >> array[i][j];
            }
        }
        bool visit[m][n] = {};
        for(int i = 0 ; i < m ; i++ ){
            for(int j = 0 ; j < n ; j++ ){
                if(array[i][j] == '@' && !visit[i][j]){
                    // bfs start 
                    queue<pair<int,int>> bfs ;
                    bfs.push(make_pair(i,j));    
                    visit[i][j] = true;
                    while(!bfs.empty()){
                        pair<int,int> now = bfs.front();
                        bfs.pop();
                        for(int d = 0 ; d < 8 ; d++){
                            int next_x = now.first+dx[d];
                            int next_y = now.second+dy[d];
                            if(next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && !visit[next_x][next_y] && array[next_x][next_y] == '@'){
                                visit[next_x][next_y] = true;
                                bfs.push(make_pair(next_x,next_y));
                            }
                        }
                    }   
                    // bfs end 
                    ans ++ ; 
                }
            }
        }
        cout << ans << endl;
    }
}
// Accepted 
