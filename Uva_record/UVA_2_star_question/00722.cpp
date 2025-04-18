#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int main(){
    int M ;
    cin >> M ;
    cin.ignore();
    
    while(M--){
        int sx , sy ;
        cin >> sx >> sy ;
        cin.ignore();
        string input ;
        vector<string> map;
        vector<vector<bool>> visited ;
        while(getline(cin,input) && input != ""){
            map.push_back(input);
            visited.push_back(vector<bool>(input.size(),false));
        }
        int ans = 0 ; 
        
        queue<pair<int,int>> next ;
        next.push({sx-1,sy-1});
        while(!next.empty()){
            pair<int,int> now = next.front();
            next.pop();
            visited[now.first][now.second] = true;
            ans ++ ; 
            for(int i = 0 ; i < 4 ; i++ ){
                int nx = now.first + dx[i];
                int ny = now.second + dy[i];
                if(nx >= 0 && ny >= 0 && nx < (int)map.size() && ny < (int)map[0].size() && !visited[nx][ny] && map[nx][ny] == '0' ){
                    next.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
        cout << ans << endl;
        if(M != 0 ) cout << endl;
        
    }
}
/*
1
02 01
1001101
0011111
0001001
1100011
1111111
1100110
1110111
*/