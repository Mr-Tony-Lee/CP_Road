#include<bits/stdc++.h>
using namespace std;
int dx[6] = {1 , -1 , 0 , 0 , 0 , 0 };
int dy[6] = {0 , 0 , 1 , -1 , 0 , 0 };
int dz[6] = {0 , 0 , 0 , 0 , 1 , -1 };

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int l, r , c ;
    while( cin >> l >> r >> c ){
        cin.ignore();
        if( l == r && r == c && c == 0 ) {
            break;
        }
        bool map[l][r][c] = {};
        int dp[l][r][c]; 
        tuple<int,int,int> start , end; 
        for(int i = 0 ; i < l ; i++ ){
            string empty;
            for(int j = 0 ; j < r ; j++ ){
                string input ;
                getline(cin,input);
                for(int k = 0 ; k < input.size() ; k++ ){
                    if(input[k] == 'S') start = {i,j,k};
                    else if (input[k] == 'E') end = {i,j,k};
                    map[i][j][k] = (input[k] != '#');
                    dp[i][j][k] = 1 << 20;
                }
            }
            getline(cin,empty); 
        }
        int sx = get<0>(start) , sy = get<1>(start) , sz = get<2>(start);
        dp[sx][sy][sz] = 0 ; 

        queue<tuple<int,int,int>> bfs ;
        bfs.push(start);
        while(!bfs.empty()){
            tuple<int,int,int> now = bfs.front();
            bfs.pop();
            int now_x = get<0>(now) , now_y = get<1>(now) , now_z = get<2>(now);
            for(int i = 0 ; i < 6; i++ ){
                int nx = now_x+dx[i] , ny = now_y+dy[i] , nz = now_z+dz[i] ; 
                if( nx >= 0 && nx < l && ny >= 0 && ny < r && nz >= 0 && nz < c &&
                    map[nx][ny][nz] && dp[now_x][now_y][now_z] + 1 < dp[nx][ny][nz] ){
                    bfs.push({nx,ny,nz});
                    dp[nx][ny][nz] = dp[now_x][now_y][now_z] + 1 ; 
                }
            }
        }
        // for(int i = 0 ; i < l ; i++ ){
        //     for(int j = 0 ; j < r ; j++ ){
        //         for(int k = 0 ; k < c ; k++ ){
        //             if(dp[i][j][k] == (1<<20)){
        //                 cout << 0 << " ";
        //             }
        //             else cout << dp[i][j][k] << " " ;
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
        int ex = get<0>(end), ey = get<1>(end), ez = get<2>(end) ; // end_x = ex 
        if(dp[ex][ey][ez] != (1<<20)){
            cout << "Escaped in " << dp[ex][ey][ez] << " minute(s)." << endl;
        }
        else{
            cout << "Trapped!" << endl;
        }
        // for(int i = 0 ; i < l ; i++ ){
        //     for(int j = 0 ; j < r ; j++ ){
        //         for(int k = 0 ; k < c ; k++ ){
        //             cout << map[i][j][k];
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
    }
}
/*
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

*/