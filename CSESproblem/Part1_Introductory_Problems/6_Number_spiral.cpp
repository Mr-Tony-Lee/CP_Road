#include<iostream>
using namespace std;
using ll = long long ;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        ll y , x ;
        cin >> y >> x ;
        ll ans = 0 ;
        ll add = 0 ;
        if( y > x ){
            ans = (y-1)*(y-1);
            if(y & 1 ){
                add = x ;
            }
            else{
                add = 2*y-x;
            }
        }
        else{
            ans = (x-1)*(x-1);
            if(x & 1 ){
                add = 2*x-y;
            }
            else{
                add = y;
            }
        }
        cout << ans + add << endl;
    }
}