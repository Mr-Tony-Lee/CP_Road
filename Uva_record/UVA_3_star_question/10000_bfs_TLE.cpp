#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);
    int n ;
    int t = 1 ; 
    while( cin >> n , n ){
        int start ;
        cin >> start ;
        int p , q ;
        int map[n+1][n+1] = {};
        int ans= 0 ; 
        int des = 0 ; 
        while( cin >> p >> q , p + q){
            map[p][q] = 1; 
        }
        queue<int> bfs ;
        bfs.push(start);
        queue<int> next_step ;
        queue<int> empty ; 
        while(!bfs.empty() || !next_step.empty()){
            int now = bfs.front();
            bfs.pop();
            for(int i = 1 ; i <= n ; i++ ){
                if(map[now][i]) {
                    next_step.push(i);
                }
            }
            if(bfs.empty()){
                ans++;
                des = next_step.front();
                bfs = next_step;
                next_step = empty;
            }
        }
        cout << "Case " << t++ << ": The longest path from "<< start << " has length " << ans-1 << ", finishing at " << des << "." << endl << endl;
    }
}
/*
2
1
1 2
0 0
5
3
1 2
3 5
3 1
2 4
4 5
0 0
5
5
5 1
5 2
5 3
5 4
4 1
4 2
0 0
0

*/