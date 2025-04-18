#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> table;

int main(){
    int x , y ;
    int kase = 0 ; 
    while(cin >> x >> y && ( x || y )){
        table.assign(101,vector<int>(101,0));
        table[x][y] = 1 ;
        int max_range = 0; 
        while(cin >> x >> y && (x || y )){
            table[x][y] = 1;
            max_range = max(max_range,max(x,y)) ;
        }
        for(int k = 1 ; k <= max_range ; k++ ){
            for(int i = 1 ; i <= max_range ; i++ ){
                for(int j = 1 ; j <= max_range ; j++ ){
                    if(table[i][k] && table[k][j] && i != j ){
                        if(table[i][j] == 0 ){
                            table[i][j] = table[i][k] + table[k][j];
                        }
                        else{
                            table[i][j] = min(table[i][k] + table[k][j] , table[i][j] ) ;
                        }
                    }
                }
            }
        } 
        double ans = 0;  
        int cnt = 0 ;
        for(int i = 1 ; i <= max_range ; i++ ){
            for(int j = 1 ; j <= max_range ; j++ ){
                // cout << table[i][j] << " ";
                if(table[i][j]){
                    ans += table[i][j];
                    cnt ++ ;
                }
                
            }
            // cout << endl;
        }
        
        cout << "Case " << ++kase << ": average length between pages = " << fixed << setprecision(3) << 1.0*ans/ cnt << " clicks" << endl;
        
    }
}
/*
1 2 2 4 1 3 3 1 4 3 0 0
1 2 1 4 4 2 2 7 7 1 0 0
0 0
*/