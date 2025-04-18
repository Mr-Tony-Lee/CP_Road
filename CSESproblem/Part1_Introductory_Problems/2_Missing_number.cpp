#include<iostream>
using namespace std;
using ll = long long ;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n ;
    cin >> n ;
    ll sum = 0 ; 
    for(int i = 0 ; i < n-1 ; i++ ){
        ll x ;
        cin >> x ;
        sum += x ;
    }
    cout << (n*(1+n))/2 - sum << endl;
}