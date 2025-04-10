#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
    cin.tie(0) ; cout.tie(0); ios::sync_with_stdio(0);
    int t ;
    cin >> t ;
    while(t--){
        int N, M ;
        cin >> N >> M ;
        vector<vector<int>> map(N+1,vector<int>(M+1 , 0));
        for(int i = 1 ; i <= N ; i++ ){
            for(int j = 1 ; j <= M ; j++ ){
                cin >> map[i][j];
            }
        }
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> pq;
        vector<vector<bool>> visit(N+1 , vector<bool>(M+1, false));
        vector<vector<int>> dis(N+1 , vector<int>(M+1, 1e9));
        pq.push({map[1][1],1,1});
        int now_i = 1 , now_j = 1 ; 
        dis[1][1] = map[1][1] ; 
        tuple<int,int,int> now = pq.top();
        pq.pop();
        while(now_i != N || now_j != M ){
            visit[now_i][now_j] = true ;
            for(int i = 0 ; i < 4 ; i++){
                int next_x = now_i + dx[i];
                int next_y = now_j + dy[i];
                if(next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M && !visit[next_x][next_y]){
                    dis[next_x][next_y] = min(dis[now_i][now_j] + map[next_x][next_y], dis[next_x][next_y]);
                    pq.push({dis[next_x][next_y], next_x , next_y });
                }
            }
            while(visit[now_i][now_j] ){
                now = pq.top(); pq.pop();
                now_i = get<1>(now); now_j = get<2>(now);
            }
        }
        cout << dis[N][M] << endl;
    }
}