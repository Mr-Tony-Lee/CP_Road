#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    int n ;
    while(cin >> n ){
        int ans = 0 ; 
        int factor[50] = {};
        factor[0] = 1 ;
        for(int i = 1 ; i < 50 ; i++ ){
            factor[i] = factor[i-1] * i ;
        }
        if(n & 1 ){
            ans = (factor[n/2])^2 * n ;
        }
        else{
            ans = (factor[n/2])^2;
        }
        cout << ans << endl;
    }
}
/*
    if n = 4 ( n 是偶數 ) -> ( 1,2,3,4) , (4,3,1,2) , (3,4,2,1) , (4,3,2,1) 
    -> 也就是中間切一半，左半邊可以任意排列，一樣會符合，右半邊也可以任意排列，一樣會符合
    if n = 5 ( n 是奇數 ) -> 最中間值可以是擺任意 n 個數 ，然後左邊一樣可以交換 
*/