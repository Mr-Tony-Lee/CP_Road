#include<iostream>
using namespace std;
using ll = long long;
int main(){
    int n ; 
    cin >> n ;
    ll before = 0 ;
    ll ans = 0 ;
    for(int i = 0 ; i < n ; i++ ){
        ll x ;
        cin >> x ;
        if(x < before){
            ans += before-x;
            x = before;
        }
        before = x ;
    }
    cout << ans << endl;
}