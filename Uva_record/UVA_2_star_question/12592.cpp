#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int N , Q ;
    cin >> N ;
    cin.ignore();
    map<string,string> a ;
    for(int i = 0 ; i < N ; i++ ){
        string first, second ;
        getline(cin, first);
        getline(cin, second);
        a[first] = second;
    }
    cin >> Q;
    cin.ignore();
    while(Q--){
        string input; 
        getline(cin, input);
        cout << a[input] << endl;
    }
}

// Accepted Uva 