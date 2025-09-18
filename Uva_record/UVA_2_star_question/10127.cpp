#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    while(cin >> n ){
        int num = 1 ;
        int cnt = 1 ;
        while(num % n != 0){    
            num %= n;   // 不斷取餘 1 % n , 11 % n , 111 % n ..... 
            num *= 10 ;
            num += 1 ;
            cnt += 1 ;
        }
        cout << cnt << endl;
    }
}