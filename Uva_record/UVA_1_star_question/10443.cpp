#include<iostream>
using namespace std;

void judge(char** map , int i , int j , int r , int c  , char** ans ){
    if(map[i][j] == 'S'){
        char win = 'R';
        if(j - 1 >= 0 && map[i][j-1] == win){
            ans[i][j] = win;
        }
        else if(i - 1 >= 0 && map[i-1][j] == win){
            ans[i][j] = win;
        }
        else if(i + 1 < r && map[i+1][j] == win){
            ans[i][j] = win;
        }
        else if( j + 1 < c && map[i][j+1] == win){
            ans[i][j] = win;    
        }
        else{
            ans[i][j] = map[i][j];
        }
    }
    else if ( map[i][j] == 'R'){
        char win = 'P';
        if(j - 1 >= 0 && map[i][j-1] == win){
            ans[i][j] = win;
        }
        else if(i - 1 >= 0 && map[i-1][j] == win){
            ans[i][j] = win;
        }
        else if(i + 1 < r && map[i+1][j] == win){
            ans[i][j] = win;
        }
        else if( j + 1 < c && map[i][j+1] == win){
            ans[i][j] = win;    
        }
        else{
            ans[i][j] = map[i][j];
        }
    }
    else{
        char win = 'S';
        if(j - 1 >= 0 && map[i][j-1] == win){
            ans[i][j] = win;
        }
        else if(i - 1 >= 0 && map[i-1][j] == win){
            ans[i][j] = win;
        }
        else if(i + 1 < r && map[i+1][j] == win){
            ans[i][j] = win;
        }
        else if( j + 1 < c && map[i][j+1] == win){
            ans[i][j] = win;    
        }
        else{
            ans[i][j] = map[i][j];
        }
    }
}

int main(){
    int times ;
    cin >> times;
    while(times--){
        int r , c , n ;
        cin >> r >> c >> n ; 
        char** map = new char*[r];
        char** ans = new char*[r];
        for(int i = 0 ; i < r ; i++ ){
            map[i] = new char [c];
            ans[i] = new char [c];
            for(int j = 0 ; j < c ; j++ ){
                cin >> map[i][j];
                ans[i][j] = ' ';
            }
        }
        while(n--){
            for(int i = 0 ; i < r ; i++ ){
                for(int j = 0 ; j < c ; j++ ){
                    judge(map,i,j,r,c,ans);
                }
            }
            for(int i = 0 ; i < r ; i++ ){
                for(int j = 0 ; j < c ; j++ ){
                    map[i][j] = ans[i][j];
                }
            }
        }
        for(int i = 0 ; i < r ; i++ ){
            for(int j = 0 ; j < c ; j++ ){
                cout << ans[i][j] ;
            }
            cout << endl;
        }
        if(times != 0 ) cout << endl;
    }
}
//Accepted