第一題:

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int k ;
    vector<int> ans(5,0);
    cin >> k ;
    for(int i = 0 ; i < 5 ; i++) {
        cin >> ans[(i+k)%5];
    }
    for(int i = 0 ; i < 5 ; i++ ){
        cout << ans[i] << " ";
    }
    cout << endl;
}

第二題:

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m , n ;
    cin >> m >> n ; 
    int A[2][3] = {
        {m,m+1,m+2},
        {m+3,m+4,m+5}
    };
    int B[3][4] = {
        {n,n+3,n+6,n+9},
        {n+1,n+4,n+7,n+10},
        {n+2,n+5,n+8,n+11}
    };
    int ans = 0 ;
    for(int i = 0 ; i < 2 ; ++ i ){
        for(int j = 0 ; j < 4 ; j++ ){
            for(int k = 0 ; k < 3 ; k++ ){
                // C[i][j] += A[i][k] * B[k][j];
                ans += A[i][k] * B[k][j];
            }
        }
    }
    cout << ans << endl;
}