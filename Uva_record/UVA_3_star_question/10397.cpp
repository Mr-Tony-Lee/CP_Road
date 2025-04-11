#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
        vector<int> parent,  rank ; 
        DSU(int n ){
            parent.resize(n+1,0);  // 每一個點最上面的root
            rank.resize(n+1,0); // 樹的rank，unite較多次的rank較高
            for(int i = 0 ; i < n+1 ; i++ ){
                parent[i] = i ; // 初始化
            }
        }
        int find(int x ){
            if(parent[x] != x ){    // 只有遇到 root 的時候會停止
                parent[x] = find(parent[x]);    // 路徑壓縮，把parent都連到root
            }
            return parent[x];
        }
        void unite(int x , int y ){
            int rootX = find(x) , rootY = find(y);  // 兩個 root 
            if(rootX != rootY){ // 如果兩個root不一樣
                if(rank[rootX] > rank[rootY]){  // 那就比 rank
                    parent[rootY] = rootX;  // 接到另外一棵樹的root上
                }
                else if (rank[rootX] < rank[rootY]){
                    parent[rootX] = rootY;
                }
                else{
                    parent[rootY] = rootX;
                    rank[rootX] ++; 
                }
            }
        }
        bool connect(int x ,int y ){
            return find(x) == find(y);  // root 一樣，就有連結
        }
};



int main(){
    cin.tie(0); cout.tie(0) ; ios::sync_with_stdio(false);
    int N ; 
    while(cin >> N ){
        vector<pair<int,int>> arr(N+1) ; 
        for(int i = 1 ; i <= N ; i++ ){
            int x , y ;
            cin >> x >> y ;
            arr[i] = {x,y};
        }
        DSU dsu(N);
        int M;
        cin >> M ; 
        int connect = 0 ; 
        for(int i = 0 ; i < M ; i++ ){
            int p1 , p2 ;
            cin >> p1 >> p2 ;
            if( !dsu.connect(p1,p2)){   // 如果沒連起來
                dsu.unite(p1,p2);   // 那就把兩個點連起來
                connect++;  // 並把已經有的路徑數 + 1
            }
        }
        priority_queue<tuple<double,int,int>, vector<tuple<double,int,int>> , greater<tuple<double,int,int>>> point ; 
        // 用priority queue存 路徑的長度，兩個點的編號
        for(int i = 1 ; i < N ; i++ ){
            for(int j = i+1 ; j <= N ; j++ ){
                if( !dsu.connect(i , j )){  // 如果兩個點沒有連起來，才要算這條路徑
                    double x = (arr[i].first-arr[j].first)*(arr[i].first-arr[j].first) ; 
                    double y = (arr[i].second-arr[j].second)*(arr[i].second-arr[j].second);
                    double length = sqrt(x + y) ;
                    point.push( { length, i , j } );
                }
            }
        }
        double ans = 0  ; 
        while( connect < N-1 ){ // 當路徑的數量等於 N-1時跳出，表示所有點都有連接
            tuple<double,int,int> now = point.top();
            point.pop();
            int p1 = get<1>(now) , p2 = get<2>(now);
            double dis = get<0>(now);
            if(!dsu.connect(p1,p2)){
                ans += dis ;
                dsu.unite(p1,p2);
                connect ++ ;
            }
        }
        cout << fixed << setprecision(2) << ans << endl;        
    }
}
/*
4
103 104
104 100
104 103
100 100
1
4 2
*/