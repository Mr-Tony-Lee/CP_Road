#include<iostream>
using namespace std;
using ll = long long ; 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n ;
    ll mod = 1e9+7;
    cin >> n ;
    ll ans = 1;
    for(int i = 0 ; i < n ; i++ ){
        ans <<= 1 ;
        ans %= mod ;
    }
    cout << ans << endl;
}