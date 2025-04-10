#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    int l , h;
    while(cin >> l >> h && (l || h)){
        int count_l = l / 5 ;
        int count_h = h / 5 ; 
        cout << count_h - count_l + 1 << endl;
    }
}
// Accepted Uva 