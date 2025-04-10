// #include<iostream>
// #include<vector>
// #include<cmath>
// using namespace std;
// using ull = unsigned ll;
// ull solve(vector<ull> fib , int bound , int n , ull base  ){
//     if(n <= bound){
//         return fib[n] % base ;
//     }
//     else{
//         return (solve(fib , bound , n-1 , base ) % base + solve(fib, bound , n-2 , base) % base ) % base ;
//     }
// }


// int main(){
//     int n , m ; 
//     while(cin >> n >> m ){
//         ull base = pow(2,m);
//         vector<ull> fib ;
//         fib.push_back(0);
//         fib.push_back(1);
//         int i = 1 ;
//         while( i != n  ){
//             i++;
//             fib.push_back((fib[i-1] % base + fib[i-2] % base)% base );
//         }
//         cout << fib[i] << endl;
//     }
// }
// Upon method TLE

#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

class Matrix{
    public:
        ll a , b , c , d , base ;
        Matrix(int , int , int , int , int);
        Matrix operator * ( const Matrix );
};
Matrix::Matrix(int a1 , int b1 , int c1 , int d1 , int b ) : a(a1),b(b1),c(c1),d(d1),base(b) {}
Matrix Matrix::operator * ( const Matrix mat2 ){
    ll copy_a = a , copy_b = b , copy_c = c , copy_d = d ;
    a = (copy_a * mat2.a + copy_b * mat2.c ) % base ;
    b = (copy_a * mat2.b + copy_b * mat2.d ) % base ;
    c = (copy_c * mat2.a + copy_d * mat2.c ) % base ;
    d = (copy_c * mat2.b + copy_d * mat2.d ) % base ;
    return *this ;
}
int main(){
    int n , m ;
    while(cin >> n >> m ){
        Matrix mul(1 , 1 , 1 , 0 , pow(2 , m)) ; 
        Matrix ans(1 , 0 , 0 , 0 , pow(2 , m)) ;
        while(n){
            if(n & 1) ans = ans * mul;
            mul = mul * mul;
            n /= 2 ; 
        }
        cout << ans.b << endl;
    }
}
//Online judge Accepted.

/*
    這題使用線性代數學到的矩陣去算 fibonacci 數列，因為矩陣可以使用快速冪，使時間複雜度是 O(log n)
    因為 Fn+2 = Fn+1 + Fn
    所以 可以寫出矩陣
    [Fn+1] = [1 1][ Fn ] = [1 1][1 1][Fn-1] ... = [1 1] ^ n * [F1]  , 
    [ Fn ]   [1 0][Fn-1]   [1 0][1 0][Fn-2] ...   [1 0]     * [F0]
    所以我們可以用矩陣快速冪算出中間的值，最後乘以F1 , F0 ，並在矩陣乘法時持續 mod m ，防止數值超出範圍
*/