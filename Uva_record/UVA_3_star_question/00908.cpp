#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
        vector<int> parent ;
        vector<int> rank;
        DSU( int n ){
            parent.resize(n+1);
            for(int i = 0 ; i <= n ; i++ ) parent[i] = i ;
            rank.resize(n+1);
            for(int i = 0 ; i <= n ; i++ ) rank[i] = 0 ;
        }
        int find(int x ){
            if(parent[x] != x ){
                parent[x] = find(parent[x]);
            }
            return parent[x] ;
        }
        void unite(int x , int y ){
            int rootX = find(x) , rootY = find(y);
            if(rootX != rootY){
                if(rank[rootX] > rank[rootY]){
                    parent[rootY] = rootX;
                }
                else if (rank[rootX] < rank[rootY]){
                    parent[rootX] = rootY;
                }
                else{
                    parent[rootY] = rootX;
                    rank[rootX] ++ ;
                }
            }   
        }
        bool connected(int x ,int y ){
            return find(x) == find(y);
        }
};

int main(){
    cin.tie(0) ; cout.tie(0);  ios::sync_with_stdio(0);
    int N ;
    int t = 1 ;
    while( cin >> N ){
        int old = 0 , ans = 0 ; 
        int x , y , dis ;
        for(int i = 0 ; i < N-1 ; i++ ){
            cin >> x >> y >> dis ;
            old += dis ; 
        }
        int k , m ;
        cin >> k ;
        // vector<tuple<int,int,int>> travel ; 
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> travel ; 
        for(int i = 0 ; i < k ; i++ ){
            cin >> x >> y >> dis ;
            travel.push({dis,x,y});
        }
        cin >> m ;
        for(int i = 0 ; i < m ; i++ ){
            cin >> x >> y >> dis ;
            travel.push({dis,x,y});
        }
        if( t != 1 ) cout << endl;
        cout << old << endl;
        DSU dsu(N);
        int count = 0 ; 
        while(!travel.empty()){
            if(count == N-1) break;
            tuple<int,int,int> now = travel.top();
            travel.pop();
            if(!dsu.connected(get<1>(now),get<2>(now))){
                dsu.unite(get<1>(now),get<2>(now));
                count++ ; 
                ans += get<0>(now);
            }
        }
        cout << ans << endl;
        t++;
    }
}
/*
5
1 2 5
1 3 5
1 4 5
1 5 5
1
2 3 2
6
1 2 5
1 3 5
1 4 5
1 5 5
3 4 8
4 5 8
*/