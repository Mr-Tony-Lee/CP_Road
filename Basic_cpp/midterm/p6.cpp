#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>>& arr , int now ,int n ){
    if( now == 1  ){
        arr[n-1][n-1] = 1 ;
        return ;
    }
    for(int i = n-now ; i < 2*n-1-n+now ; i++ ){
        for(int j = n-now ; j < 2*n-1-n+now ; j++ ){
            if( i == n-now ){
                arr[i][j] = now ; 
            }
            else if ( i == 2*n-1-n+now-1 ){
                arr[i][j] = now ;
            }
            else{
                if(j == n-now ){
                    arr[i][j] = now ;
                }
                if(j == 2*n-1-n+now-1){
                    arr[i][j] = now ;
                }
            }
        }
    } 
    solve(arr,now-1 ,n );
}

int main(){
    int n ;
    cin >> n ;
    vector<vector<int>> arr(2*n-1,vector<int>(2*n-1,0));
    solve(arr, n , n  );    
    for(int i = 0 ; i < 2*n-1 ; i++ ){
        for(int j = 0 ; j < 2*n-1 ; j++ ){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
}