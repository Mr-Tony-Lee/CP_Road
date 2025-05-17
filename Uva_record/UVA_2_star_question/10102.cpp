#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
    ios::sync_with_stdio(0); cin.tie(0) ; cout.tie(0) ;
    int n ;
    while(cin >> n ){
        cin.ignore();
        vector<vector<int>> map(n,vector<int>(n));
        vector<pair<int,int>> record1;
        for(int i = 0 ; i < n ; i++ ){
            string input ;
            getline(cin,input);
            for(int j = 0 ; j < n ; j++ ){
                map[i][j] = input[j] - '0';
                if(map[i][j] == 1){
                    record1.push_back({i,j});
                }
            }
        }
        int maxd = 0 ;
        for(int i = 0 ; i < (int)record1.size() ; i++ ){
            priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> pq;
            vector<vector<bool>> visited(n,vector<bool>(n,false));
            pq.push({0,record1[i].first , record1[i].second});
            int d = 0 ; 
            bool find = false;
            while(!pq.empty()){
                tuple<int,int,int> now = pq.top();
                pq.pop();
                int s = get<0>(now) , ni = get<1>(now), nj = get<2>(now);
                visited[ni][nj] = true;
                for(int j = 0 ; j < 4 ; j++ ){
                    int nx = ni + dx[j];
                    int ny = nj + dy[j];
                    if((0 <= nx && nx < n ) && (0 <= ny && ny < n ) && !visited[nx][ny]){
                        pq.push({s+1,nx,ny});
                        visited[nx][ny] = true;
                        if(map[nx][ny] == 3 ){
                            d = s+1 ; 
                            find = true ;
                            break;
                        }
                    }
                }
                if(find) break;
            }
            maxd = max(d,maxd); 
        }
        cout << maxd << endl;
    }
}
/*
10
1111111111
1111111111
1111111111
1111111111
1111111111
1111111111
1111111111
1111111111
1111111111
1111111113
*/