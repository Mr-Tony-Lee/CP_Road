#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

void solve(unordered_map<int,vector<int>>& map , int z , int& count ,vector<bool>& visited){
    for(int i = 0 ; i < (int)map[z].size() ; i++ ){
        if(!visited[map[z][i]]){
            count++;
            visited[map[z][i]] = true;
            solve(map , map[z][i] , count , visited);
        }
    }
}

int main(){
    int times ;
    cin >> times ;
    while(times--){
        int n , m , l ;
        int ans = 0 ; 
        cin >> n >> m >> l ;
        unordered_map<int,vector<int>> relation;
        vector<bool> visited(n+1, false );
        for(int i = 0 ; i < m ; i++ ){
            int x , y ;
            cin >> x >> y ;
            relation[x].push_back(y);
        }
        while(l--){
            int z ;
            cin >> z ;
            if(!visited[z]){
                visited[z] = true;
                ans++;
                solve(relation, z ,ans , visited);
            }
        }
        cout << ans << endl;
    }
}