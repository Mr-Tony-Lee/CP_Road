#include<bits/stdc++.h>
using namespace std;

int dx[8] = {1,1,1,-1,-1,-1,0,0};
int dy[8] = {1,-1,0,1,-1,0,1,-1};

int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);
    int t ;
    cin >> t;
    while(t--){
        int m , n ;
        cin >> m >> n ;
        cin.ignore();
        char map[m][n];
        for(int i = 0 ; i < m ; i++ ){
            string input ;
            getline(cin,input);
            for(int j = 0 ; j < n ; j++ ){
                map[i][j] = tolower(input[j]);
            }
        }
        int s ;
        cin >> s ;
        cin.ignore();
        while(s--){
            string input ;
            getline(cin,input);
            int ax , ay ;
            for(int i = 0 ; i < m ; i++ ){
                for(int j = 0 ; j < n ; j++ ){
                    if(map[i][j] == tolower(input[0])){
                        if((int)input.size() == 1 ){
                            ax = i+1 ;
                            ay = j+1; 
                            goto Here;
                        }
                        for(int k = 0 ; k < 8 ;k++ ){
                            int nx = i + dx[k] , ny = j + dy[k];
                            if(nx >= 0 && nx < m && ny >= 0 && ny < n ){
                                bool state = true ;
                                for(int z = 1 ; z < (int)input.size() ; z++ ){
                                    if(!(nx >= 0 && nx < m && ny >= 0 && ny < n) ){
                                        state = false ;
                                        break;
                                    }
                                    if(map[nx][ny] != tolower(input[z])){
                                        state = false ;
                                        break;
                                    }
                                    nx += dx[k] , ny += dy[k];
                                }
                                if(state){
                                    ax = i+1 ;
                                    ay = j+1; 
                                    goto Here;
                                    
                                }
                            }
                        }
                    }
                }
            }
            Here:
            cout << ax << " " << ay << endl;
        }
        if(t){
            cout << endl;
        }
    }
}
/*

1
8 11
abcDEFGhigg
hEbkWalDork
FtyAwaldORm
FtsimrLqsrc
byoArBeDeyv
Klcbqwikomk
strEBGadhrb
yUiqlxcnBjf
4
Waldorf
Bambi
Betty
Dagbert

*/