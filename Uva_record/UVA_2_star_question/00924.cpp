#include<bits/stdc++.h>
using namespace std;
int N ;
vector<vector<int>> relate;
vector<bool> visited;

pair<int,int> bfs(int source){
    queue<int> this_turn ;
    queue<int> next;
    queue<int> empty_queue;
    this_turn.push(source);
    int max_size = 0 ;
    int max_round = 0 ;
    int round = 1 ;
    while(1){
        while(!this_turn.empty()){
            int now = this_turn.front();
            this_turn.pop();
            visited[now] = true;
            for(int i = 0 ; i < (int)relate[now].size(); i++ ){
                if(!visited[relate[now][i]]){
                    next.push(relate[now][i]);
                    visited[relate[now][i]] = true;
                }
            }
        }
        if(next.size() > max_size){
            max_size = next.size();
            max_round = round ; 
        }
        this_turn.swap(next) ;
        round++;
        if(this_turn.size() == 0 ) break;
    }
    return {max_size , max_round};
}

int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++ ){
        vector<int> fri ;
        int n ;
        cin >> n ;
        for(int j = 0 ; j < n ; j++ ){
            int x ;
            cin >> x ;
            fri.push_back(x);
        }
        relate.push_back(fri);
    }
    int t ;
    cin >> t; 
    while(t--){
        int M , D ;
        int source ;
        cin >> source ; 
        visited.assign(N,false);
        auto pair = bfs(source);
        M = pair.first , D = pair.second;
        if( M == 0 ){
            cout << 0 << endl;
        }
        else{
            cout << M << " " << D << endl;
        }
    }
}
/*
6
2 1 2
2 3 4
3 0 4 5
1 4
0
2 0 2
3
0
4
5
*/