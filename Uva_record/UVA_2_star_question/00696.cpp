#include<bits/stdc++.h>
using namespace std;
int M , N ; 
int main(){
    while(cin >> M >> N){
        if( M == N && N == 0 ) break;
        int a = min(M,N) , b = max(M,N);
        int ans = 0 ; 
        if( a == 1 ){
            ans = b ;
        }       
        else if ( a == 2 ){
            int c = b % 4 ;
            if(c){
                if( c == 1 ){   
                    /*
                    xxoox
                    xxoox
                    */
                    ans = (b/4)*4 + 2 ;
                }
                else if ( c >= 2 ){
                    /*
                    xxooxx
                    xxooxx
                    
                    or 
                    xxooxxo
                    xxooxxo
                    */
                    ans = (b/4)*4 + 4 ;
                }
            }
            else{
                ans = (b/4)*4;
            }
        }
        else{
            /*
            交叉擺
            xox
            oxo
            xox
            -> x 的數量 3*3+1/2
            xoxo
            oxox
            xoxo
            -> x 的數量 3*4/2

            */
            ans = (a*b+1) / 2;
        }   
        cout << ans  << " knights may be placed on a " << M << " row " << N << " column board." << endl;
    }
}
// 參考網站 : https://naivered.github.io/2018/03/16/Problem_Solving/UVa/UVa-696-How-Many-Knights/

/*
2 3
5 5 
4 7
0 0 
*/