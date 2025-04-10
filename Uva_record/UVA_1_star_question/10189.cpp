#include<iostream>
using namespace std;

int main(){
    int Case = 1 ;
    int n , m ;
    while(cin >> n >> m){
        if(n == 0 && m == 0 ){
            break;
        }
        char map[n][m] ;
        for(int i = 0; i < n ; i++ ){
            for(int j = 0 ; j < m ; j++ ){
                cin >> map[i][j] ;
            }
        }
        char ans[n][m];
        if(Case != 1 ){
            cout << endl;
        }
        cout << "Field #" << Case++ << ":" << endl;
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m; j++ ){
                int count = 0 ; 
                if( i-1 >= 0 && j-1 >= 0 && map[i-1][j-1] == '*'){
                    count++;
                }
                if( i-1 >= 0 && map[i-1][j] == '*' ){
                    count++;
                }
                if( i-1 >= 0 && j+1 < n && map[i-1][j+1] == '*'){
                    count++;
                }
                if( j-1 >= 0 && map[i][j-1] == '*'){
                    count++;
                }
                if(  j+1 < m && map[i][j+1] == '*'){
                    count++;
                }
                if( i+1 < n && j-1 >= 0 && map[i+1][j-1] == '*'){
                    count++;
                }
                if( i+1 < n && map[i+1][j] == '*'){
                    count++;
                }
                if( i+1 < n && j+1 < m && map[i+1][j+1] == '*'){
                    count++;
                }
                if(map[i][j] != '*') ans[i][j] = '0' + count ;
                else ans[i][j] = '*';
                cout << ans[i][j] ;
            }
            cout << endl;
        }
        
    }
}
//8ms, 332KB