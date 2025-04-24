#include<bits/stdc++.h>
using namespace std;


void UpsideDown(vector<vector<int>>& mat , int n , int now){
    
    /*
    o
    oxxx
    oxxx
    oxxx
    o
    */
    for(int i = now ; i < n-now ; i++ ){
        swap(mat[now][i] , mat[n-1-now][i]);
    }
    for(int i = now+1 ; i < (n/2) ; i++ ){
        swap(mat[i][now] , mat[n-1-i][now]);
        swap(mat[i][n-1-now], mat[n-1-i][n-1-now]);
    }

}

void LeftRight(vector<vector<int>>& mat , int n , int now){
    for(int i = now ; i < n-now ; i++ ){
        swap(mat[i][now] , mat[i][n-1-now]);
    }
    for(int i = now+1 ; i < (n/2) ; i++ ){
        swap(mat[now][i] , mat[now][n-1-i]);
        swap(mat[n-1-now][i], mat[n-1-now][n-1-i]);
    }
}

void MainDiagonal(vector<vector<int>>& mat , int n , int now){
    for(int i = now+1 ; i < n-now-1 ; i++ ){
        swap(mat[i][now] , mat[now][i]);
    }
    for(int i = now ; i < n-now-1; i++ ){
        swap(mat[n-1-now][i], mat[i][n-1-now]);
    }
}

void InverseDiagonal(vector<vector<int>>& mat , int n , int now){
    for(int i = now ; i < n-now-1 ; i++ ){
        swap(mat[now][i],mat[n-1-i][n-now-1]);
    }
    for(int i = now+1 ; i < n-now-1 ; i++ ){
        swap(mat[i][now] , mat[n-1-now][n-1-i]);
    }

}

int main(){
    int t ;
    cin >> t;
    while(t--){
        int n ;
        cin >> n ;
        vector<vector<int>> mat(n,vector<int>(n));
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < n ; j++ ){
                cin >> mat[i][j];
            }
        }
        int ring_num = (n+1)/2;
        for(int k = 0 ; k < ring_num ; k++ ){
            int T ; 
            cin >> T;
            while(T--){
                int c;
                cin >> c;
                switch (c)
                {
                case 1:
                    UpsideDown(mat, n , k);
                    break;
                case 2:
                    LeftRight(mat, n , k);
                    break;
                case 3:
                    MainDiagonal(mat, n , k);
                    break;
                case 4:
                    InverseDiagonal(mat, n , k);
                    break;
                default:
                    break;
                }
            }
        }
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < n ; j++ ){
                if( j == 0 ){
                    cout << mat[i][j];
                }
                else{
                    cout << " " << mat[i][j];
                }
            }
            cout << endl;
        }
        
    }
}
/*
4
3
1 2 3
4 5 6
7 8 9
1 4
*/