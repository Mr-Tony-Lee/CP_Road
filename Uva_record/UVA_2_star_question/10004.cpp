#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    while(cin >> n && n ){
        vector<vector<int>> map(n);
        int l ;
        cin >> l ;
        int max = 0 , max_size = 0 ; 
        for(int i = 0 ; i < l ; i++ ){
            int x , y ;
            cin >> x >> y; 
            map[x].push_back(y);
            map[y].push_back(x);
            if( max_size < (int)map[x].size()){
                max_size = map[x].size();
                max = x ;
            }
            if( max_size < (int)map[y].size()){
                max_size = map[y].size();
                max = y ;
            }
        }
        vector<int> color(n,0);
        vector<bool> visited(n,false);
        queue<int> q ;
        q.push(max);
        color[max] = 1 ;
        bool flag = true;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            visited[now] = true;
            for(int i = 0 ; i < map[now].size() ; i++ ){
                if(color[now] == 1 ){
                    if(color[map[now][i]] == color[now] ){
                        flag = false ;
                        break;
                    }
                    color[map[now][i]] = 2 ;
                    if(!visited[map[now][i]])
                        q.push(map[now][i]);
                }
                if(color[now] == 2 ){
                    if(color[map[now][i]] == color[now] ){
                        flag = false ;
                        break;
                    }
                    color[map[now][i]] = 1 ;
                    if(!visited[map[now][i]])
                        q.push(map[now][i]);
                }
            }
        }
        if(flag) cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
}
/*
3
3
0 1
1 2
2 0
3
2
0 1
1 2
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8 
0
*/