#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> factorial(1001,vector<int>(3000,0));
    factorial[0][0] = 1;
    factorial[1][0] = 1;
    vector<int> size (1001,1);
    for (int i = 2; i <= 1000; i++) {
        int carry = 0 ;
        // 做數字運算 ( class bignums )
        for(int j = 0 ; j < size[i-1] ; j++ ){
            int new_digit = factorial[i-1][j]*i + carry ;
            carry = new_digit / 10 ;
            factorial[i][j] = new_digit % 10 ;
        }
        int k = size[i-1];
        while( carry > 0 ){
            factorial[i][k] += carry % 10 ;
            carry /= 10 ;
            k++;
        }
        size[i] = k;
    }
    int n;
    while (cin >> n) {
        int ans = 0;
        for(int i = 0 ; i <= size[n] ; i++ ){
            ans += factorial[n][i] ;
        }
        cout << ans << endl;
    }
}
