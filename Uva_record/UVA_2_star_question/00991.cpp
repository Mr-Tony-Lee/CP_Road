#include<bits/stdc++.h>
using namespace std;
int N = 25;

int main(){
    int C[N][N] = {} ;
    for(int i = 0 ; i < N ; i++ ){
        C[i][0] = 1 ;
        C[i][i] = 1 ;
    }
    //  巴斯卡三角形，求出 C(n,n)
    for(int i = 1 ; i < N ; i++ ){
        for(int j = 1 ; j < i ; j++ ){
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
    int n ;
    bool first = true ;
    while(cin >> n ){
        if( n == 0 ) break;
        if(first) first = false;
        else cout << endl;
        
        cout << C[2*n][n] / (n+1) << endl;
    }
}

// Catalan number 
// https://yuihuang.com/uva-991/