#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    while(cin >> n , n ){
        map<pair<int,int>,int> arr;
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++ ){
            int a , b ;
            cin >> a >> b;
            if(arr.count({b,a})) cnt--, arr[{b,a}]--;
            else cnt++ , arr[{a,b}]++;
        }
        cout << (cnt == 0 ? "YES" : "NO") << endl;
    }
}