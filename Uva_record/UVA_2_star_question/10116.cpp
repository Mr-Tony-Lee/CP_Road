#include<bits/stdc++.h>
using namespace std;

int main(){
    int r , c , ec ;    // row , column , entercolumn
    while(cin >> r >> c >> ec){
        if( r == 0 && r == c && c == ec ){
            break;
        }
        cin.ignore();
        vector<vector<char>> grid(r,vector<char>(c,' '));
        for(int i = 0 ; i < r ; i++ ){
            string input ;
            getline(cin ,input);
            for(int j = 0 ; j < c ; j++ ){
                grid[i][j] = input[j];
            }
        }
        int ans = 1 ;
        int lans = 0 ; 
        map<pair<int,int>,int> cnt ;
        bool loop = false;
        int nr = 0 , nc = ec-1;
        bool out = false; 
        while(!loop && !out ){
            if(cnt[{nr,nc}] == 0 ){
                cnt[{nr,nc}] = ans++;
                if(grid[nr][nc] == 'N'){
                    nr--;
                }
                else if (grid[nr][nc] == 'E'){
                    nc++;
                }
                else if (grid[nr][nc] == 'S'){
                    nr++;
                }
                else{
                    nc--;
                }
                if(nc < 0 || nr < 0 || nc >= c || nr >= r ){
                    out = true;
                    break;
                }
            }
            else{
                loop = true ;
                lans = ans - cnt[{nr,nc}];
                break;
            }
        }
        if(out){
            cout << ans-1 << " step(s) to exit" << endl;
        }
        if(loop){
            cout << cnt[{nr,nc}]-1 << " step(s) before a loop of " << lans << " step(s)" << endl;
        }
    }
}
/*
3 6 5
NEESWE
WWWESS
SNWWWW

4 5 1
SESWE
EESNW
NWEEN
EWSEN
*/