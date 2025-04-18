#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long ;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);    
    int n ;
    cin >> n ;
    vector<int> p(n) ;
    for(int i = 0 ; i < n ; i++ ){
        cin >> p[i];
    }
    sort(p.begin() , p.end());
    int middle = p[p.size()/2];
    ll ans = 0 ;
    for(int i = 0 ; i < n ; i++ ){
        ans += abs(p[i] - middle);
    }
    cout << ans << endl;
}