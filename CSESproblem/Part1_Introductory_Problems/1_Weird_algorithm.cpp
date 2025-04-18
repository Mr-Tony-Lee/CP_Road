#include<iostream>
using namespace std ;
using ull = unsigned long long ;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ull n ; 
    cin >> n ;
    cout << n << " " ;
    while(n != 1 ){
        if(n & 1 ){
            n = 3*n+1;
            cout << n << " ";
            n >>= 1;
            cout << n << " ";
        }
        else{
            n >>= 1 ;
            cout << n << " ";
        }
    }
    cout << endl;
}