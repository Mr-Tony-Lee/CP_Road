#include<bits/stdc++.h>
using namespace std;

typedef pair<double, double> p ;

typedef tuple<double,int,int> dp;

double dis(p a , p b ){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second-b.second)*(a.second-b.second));
}

class DSU{
    public:
        vector<int> parent;
        vector<int> rank;
        DSU(int n ){
            parent.resize(n+1);
            rank.resize(n+1);
            for(int i = 0 ; i <= n ; i++ ){
                parent[i] = i ;
                rank[i] = 0 ;
            }
        }
        int find(int x ){
            if(parent[x] != x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        void unite(int x , int y ){
            int rootx = find(x) , rooty = find(y);
            if(rank[rootx] > rank[rooty]){
                parent[rooty] = rootx ;
            }
            else if (rank[rootx] < rank[rooty]){
                parent[rootx] = rooty;
            }
            else{
                parent[rooty] = rootx ;
                rank[rootx]++ ;
            }
        }
        bool connect(int x , int y ){
            return find(x) == find(y);
        }
};

int main(){
    int t ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        vector<p> point ;
        for(int i = 0 ; i < n ; i++ ){
            double x , y ;
            cin >> x >> y ;
            point.push_back({x,y});
        }
        priority_queue<dp , vector<dp> , greater<dp>> pq;
        for(int i = 0 ; i < n-1 ; i++ ){
            for(int j = i+1 ; j < n ; j++ ){
                pq.push({dis(point[i],point[j]),i+1,j+1});
            }
        }
        DSU dsu(n);
        int count = 0 ;
        double ans = 0 ;
        while(!pq.empty()){
            dp now = pq.top();
            pq.pop();
            if(!dsu.connect(get<1>(now) , get<2>(now))){
                dsu.unite(get<1>(now) , get<2>(now));
                ans += get<0>(now);
                count ++ ;
            }
            if(count == n-1) break;
        }
        cout << fixed << setprecision(2) << ans << endl;
        if(t) cout << endl;
    }
}
/*
1
3
1.0 1.0
2.0 2.0
2.0 4.0

*/