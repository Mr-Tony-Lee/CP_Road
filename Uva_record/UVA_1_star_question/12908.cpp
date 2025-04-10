#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

int main(){
    ll s ;
    vector<int> table ;
    for(int i = 0 ; i <= 20000 ; i++ ){
        table.push_back((i*(i+1))/2);
    }
    while( cin >> s ){
        if(!s) return;
        auto iter = upper_bound(table.begin(), table.end() , s);
        cout << *iter-s << " " << iter-table.begin() << endl;
    }
}
// Accepted Uva