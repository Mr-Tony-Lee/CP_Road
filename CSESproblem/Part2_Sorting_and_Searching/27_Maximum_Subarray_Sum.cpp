#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long ;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;  
    vector<ll> a;
    for(int i = 0 ; i < n ; i++ ){
        ll x ;
        cin >> x;
        a.push_back(x);
    }
    ll maxSum = a[0];
    ll now_sum = 0; 
    ll zero = 0 ;
    for(int i = 0 ; i < n ; i++ ){
        now_sum = max(now_sum , zero );   // 如果now_sum 小於0 ，就沒必要在往下加，直接從0開始加
        now_sum += a[i];
        maxSum = max(maxSum,now_sum);
    }
    cout << maxSum << endl;
}