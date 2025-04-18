#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1 , -1 , 0 , 0};
int dy[4] = {0 , 0 , 1 , -1};
int w,  h;
vector<vector<bool>> visited;
vector<vector<char>> table;

bool inside(int x , int y ){
    if(x >= 0 && x < h && y >= 0 && y < w){
        return true ;
    }
    return false;
}

int bfs(int x , int y ){
    queue<pair<int,int>> next_X ;
    queue<pair<int,int>> next;
    next.push({x,y});
    int ans = 0 ; 
    while(!next.empty()){
        bool state = false;
        pair<int,int> now = next.front();
        next.pop();
        visited[now.first][now.second] = true;
        if(table[now.first][now.second] == 'X') state = true ;
        for(int i = 0 ; i < 4 ; i++ ){
            int nx = now.first+dx[i];
            int ny = now.second+dy[i];
            if(inside(nx,ny) && !visited[nx][ny] && table[nx][ny] != '.'){
                visited[nx][ny] = true ;
                if( table[nx][ny] == 'X' ){
                    next_X.push({nx,ny});
                }
                else if ( table[nx][ny] == '*' ){
                    next.push({nx,ny});
                }
            }
        }
        while(!next_X.empty()){
            state = true;
            pair<int,int> nowX = next_X.front();
            next_X.pop();
            visited[nowX.first][nowX.second] = true ;
            for(int i = 0 ; i < 4 ; i++ ){
                int nx = nowX.first+dx[i];
                int ny = nowX.second+dy[i];
                if(inside(nx,ny) && !visited[nx][ny] && table[nx][ny] != '.'){
                    visited[nx][ny] = true ;
                    if( table[nx][ny] == 'X' ){
                        next_X.push({nx,ny});
                    }
                    else if ( table[nx][ny] == '*' ){
                        next.push({nx,ny});
                    }
                }
            }   
        }
        if(state) ans++;
    }
    return ans ;   
}

int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);
    int kase = 0 ; 
    while(cin >> w >> h ){
        if( w == h && h == 0 ) break;
        cin.ignore();

        table.assign(h, vector<char>(w));
        visited.assign(h, vector<bool>(w, false));

        vector<int> ans ; // record the number of dice of each region 
        for(int i = 0 ; i < h ; i++ ){
            string input ;
            getline(cin,input);
            for(int j = 0 ; j < (int)input.size() ; j++ ){
                table[i][j] = input[j];
            }
        }
        
        for(int i = 0 ; i < h ; i++ ){
            for(int j = 0 ; j < w ; j++ ){
                if(table[i][j] != '.' && !visited[i][j]){
                    int num = bfs(i,j);
                    if(num){
                        ans.push_back(num);
                    }
                }
            }
        }
        cout << "Throw " << ++kase << endl;
        sort(ans.begin(),ans.end());
        for(int i = 0 ; i < (int)ans.size() ; i++ ){
            if(i != (int)ans.size()-1){
                cout << ans[i] << " ";
            }
            else {
                cout << ans[i] << endl;
            }
        }
        cout << endl;
    }   
}

/*
30 15
..............................
..............................
...............*..............
...*****......****............
...*X***.....**X***...........
...*****....***X**............
...***X*.....****.............
...*****.......*..............
..............................
........***........******.....
.......**X****.....*X**X*.....
......*******......******.....
.....****X**.......*X**X*.....
........***........******.....
..............................
0 0

*/