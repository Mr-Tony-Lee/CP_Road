#include<bits/stdc++.h>
using namespace std;
using ll = long long ;


int main(){
    int T ;
    cin >> T ;
    while(T--){
        int n ;
        set<int> old , ans ;
        cin >> n ;
        int x ;
        cin >> x; 
        old.insert(x);
        for(int i = 1; i < n ; i++ ){
            cin >> x ;
            ans.insert(*old.rbegin()-x);
            old.insert(x);
        }
        cout << *ans.rbegin() << endl;
    }
}

// Accepted Uva