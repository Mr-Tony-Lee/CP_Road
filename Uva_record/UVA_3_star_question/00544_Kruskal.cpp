#include<bits/stdc++.h>
using namespace std;

class DSU{  // disjoint set union 
    public:
        vector<int> parent , rank;
        DSU(int n ){
            parent.resize(n+1);
            rank.resize(n+1);
            for(int i = 0 ; i <= n ; i++ ) parent[i] = i;   // 一開始自己就是Parent 
            for(int i = 0 ; i <= n ; i++ ) rank[i] = 0 ; 
        }
        int find(int x){
            if(parent[x] != x ){
                parent[x] = find(parent[x]);
            }
            return parent[x];
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
        bool connected(int x , int y ){
            return find(x) == find(y);
        }  
};

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n , r ;
    int t = 1 ; 
    while(cin >> n >> r){
        if(n == r && r == 0 ) break;
        vector<vector<int>> city(n+1,vector<int>(n+1,0)) ;
        int city_cnt = 1 ; 
        unordered_map<string,int> name ;
        priority_queue<tuple<int,int,int>> travel;
        for(int i = 0 ; i < r ; i++ ){
            string c1 , c2 ;
            int tons ;
            cin >> c1 >> c2 ;
            cin >> tons ;
            if(name.count(c1) == 0 ) name[c1] = city_cnt++;
            if(name.count(c2) == 0 ) name[c2] = city_cnt++ ;    
            travel.push({tons,name[c1],name[c2]});
        }
        string start , dest ;
        cin >> start >> dest ;   
        DSU dsu_set(n);
        int ans = INT_MAX ;
        while(!travel.empty()){
            tuple<int,int,int> now = travel.top();
            travel.pop();
            dsu_set.unite(get<1>(now),get<2>(now));
            ans = min(get<0>(now), ans );
            if(dsu_set.connected(name[start],name[dest])) break;
        }
        cout << "Scenario #" << t++ << endl;
        cout << ans << " tons" << endl;
        cout << endl;
    }
}
// 每次取最大的邊，只要有路可以走到從起點走到終點，就結束
// 用 dsu 判斷是否連通( parent 是否為同一個 )