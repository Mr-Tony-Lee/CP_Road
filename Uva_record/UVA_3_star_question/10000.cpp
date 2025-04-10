#include<bits/stdc++.h>
using namespace std;

// SPFA (shortest path faster algorithm)    
int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(false);
    int n ;
    int t = 1 ;
    while( cin >> n , n ){
        int start ;
        cin >> start;
        vector<vector<bool>> map(n+1, vector<bool>(n+1,false));
        int x , y ;
        while(cin >> x >> y , x+y){
            map[x][y] = true;
        }
        vector<int> distance(n+1,0);
        vector<bool> inqueue(n+1 , false);
        queue<int> next;
        next.push(start);
        while(!next.empty()){
            int now = next.front();
            next.pop();
            inqueue[now] = false;
            for(int i = 1 ; i <= n ; i++ ){
                if(map[now][i] && distance[now]+1 > distance[i]){
                    distance[i] = distance[now]+1;
                    if(!inqueue[i]){
                        next.push(i);
                        inqueue[i] = true;
                    }
                }
            }
        }
        int des = 0 ; 
        for(int i = 1 ; i <= n ; i++ ){
            if(distance[i] > distance[des]){
                des = i ;
            }
        }
        cout << "Case " << t++ << ": The longest path from "<< start << " has length " << distance[des] << ", finishing at " << des << "." << endl << endl;
    }
}