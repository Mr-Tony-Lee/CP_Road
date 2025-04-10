#include<bits/stdc++.h>
using namespace std;

class DSU{
    public: 
        vector<int> parent;
        vector<int> rank;
        DSU(int n ){
            parent.resize(n+1);
            rank.resize(n+1);
            for(int i = 0 ; i <= n ; i++ ) parent[i] = i ;
        }
        int find(int x ){
            if(parent[x] != x ){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        void unite(int x , int y ){
            int rX = find(x) , rY = find(y);
            if(rX != rY ){
                if(rank[rX] > rank[rY]){
                    parent[rY] = rX;
                }
                else if (rank[rX] < rank[rY]){
                    parent[rX] = rY;
                }
                else{
                    parent[rY] = rX;
                    rank[rX] ++ ; 
                }
            }
        }
        bool connected(int x , int y ){
            return find(x) == find(y);
        }
};

int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);
    int t ;
    cin >> t ;
    for(int k = 1 ; k <= t ; k++ ) {
        int n ;
        cin >> n ;
        cin.ignore();
        int now = 1 ;
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> travel ;
        for(int i = 1 ; i <= n ; i++ ){
            string input ;
            getline(cin,input);
            int dis = 0 ;
            for(int j = 0 ; j < (int)input.size() ; j++ ){ 
                if(input[j] >= '0' && input[j] <= '9'){
                    dis = dis*10 + input[j]-'0';
                }
                else if (input[j] == ','){
                    if(dis > 0 ){
                        travel.push({dis,i,now});
                    }
                    dis = 0 ; 
                    now++;
                }
            }
            if(dis > 0 ){
                travel.push({dis,i,now});
            }
            now = 1 ;
        }
        vector<tuple<int,int,int>> ans ;
        DSU dsu(n);
        int count = 0 ; 
        
        while(!travel.empty()){
            if(count == n-1 ) break;
            tuple<int,int,int> now = travel.top();
            travel.pop();
            // cout << get<0>(now) << " " << get<1>(now) << " " << get<2>(now) << endl;
            if(!dsu.connected(get<1>(now) , get<2>(now))){
                count++; 
                dsu.unite(get<1>(now) , get<2>(now));
                ans.push_back(now);
            }
        }
        cout << "Case " << k << ":" << endl;
        for(int i = 0 ; i < (int)ans.size() ; i++ ){
            cout << char(get<1>(ans[i]) + 'A' -1) << "-" << char(get<2>(ans[i]) + 'A' -1) << " " << get<0>(ans[i]) << endl;
        }
    }
    // 使用 kruskal 去創造 MST， 連通就break(連通只需要N-1條edge)
}