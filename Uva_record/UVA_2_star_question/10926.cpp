#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    while(cin >> n && n ){
        vector<vector<int>> map;
        for(int i = 0 ; i <= 101 ; i++ ){
            vector<int> row(101 , 0);
            map.push_back(row);
        }
        for(int i = 1 ; i <= n ; i++ ){
            int N ; 
            cin >> N ;
            while(N--){
                int t ; 
                cin >> t ;
                map[i][t] = 1 ; 
            }   
        }
        int ans = 0 ; 
        int ans_num = 0 ;
        for(int k = 1 ; k <= n ; k++ ){
            for(int i = 1 ; i <= n ; i++ ){
                for(int j = 1 ; j <= n ; j++ ){
                    if(map[i][k] && map[k][j])  // i 到 j 有 indirect only if i dependency to k and k dependency to j
                        map[i][j] = max(map[i][k], map[k][j]);
                }
            }
        }
        
        for(int i = 1 ; i <= n ; i++  ){
            int count = 0;
            for(int j = 1 ; j <= n ; j++ ){
                if(map[i][j]) count++; 
            }
            if( count > ans ){
                ans = count;
                ans_num = i ; 
            }
        }
        cout << ans_num << endl;
    }
}
// 從路徑的觀點來看這題， 如果indirect，那一定有路可以走到，所以最後就是路徑常大於等於 1 的就有 dependency 
