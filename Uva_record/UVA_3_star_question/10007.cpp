#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);
    int n ;
    while(cin >> n , n ){
        // 2n! / (n!*n!*(n+1)) -> 這是不同形狀的binary tree 個數 
        // 但本題是如果形狀相同，還可以調換node的順序，所以要乘以 n!
        // 那最後就是 (n+2) * (n+3) ... * 2n
        int ans[5000] = {}; ans[0] = 1 ;
        int ans_size = 1 ;
        for(int i = n+2 ; i <= 2*n ; i++ ){
            int carry = 0 ; 
            for(int j = 0 ; j < ans_size ; j++ ){
                int new_digit = ans[j] * i + carry ; 
                carry = new_digit / 10 ; 
                ans[j] = new_digit % 10 ; 
            }
            while( carry > 0 ){
                ans[ans_size++] = carry % 10 ;
                carry /= 10 ;
            }
        }
        for(int i = ans_size-1 ; i >= 0 ; i-- ){
            cout << ans[i] ;
        }
        cout << endl;
    }
}