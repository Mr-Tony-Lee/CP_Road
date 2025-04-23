#include<bits/stdc++.h>
using namespace std;




int main(){
    int t ;
    cin >> t;
    while(t--){
        int m , n ;
        cin >> m >> n ;
        vector<vector<int>> table(1000);
        for(int i = 0 ; i < m ; i++ ){
            string a , b ;
            cin >> a >> b ;
            table[a[0]-'A'].push_back(b[0]-'A');
            table[b[0]-'A'].push_back(a[0]-'A');
        }
        for(int i = 0 ; i < n ; i++ ){
            vector<int> parent(26,-1) ;
            vector<bool> visited(26,false);
            string a , b ;
            cin >> a >> b ;
            int s = a[0]-'A';
            int d = b[0]-'A';
            queue<int> q ;
            q.push(s);
            while(!q.empty() && q.front() != d ){
                int now = q.front();
                q.pop();
                visited[now] = true;
                for(int i = 0 ; i < (int)table[now].size() ; i++ ){
                    int next_step = table[now][i];
                    if(!visited[next_step]){
                        q.push(next_step);
                        visited[next_step] = true;
                        parent[next_step] = now;
                    }
                }
            }
            vector<char> ans ;
            int now = d ;
            while(now != -1 ){
                ans.push_back(now + 'A');
                now = parent[now];
            }
            for(int i = ans.size()-1 ; i >= 0  ; --i ){
                cout << ans[i];
            }
            cout << endl;
        }
        if(t) cout << endl;
    }
}
/*
1
7 3
Rome Turin
Turin Venice
Turin Genoa
Rome Pisa
Pisa Florence
Venice Athens
Turin Milan
Turin Pisa
Milan Florence
Athens Genoa
*/