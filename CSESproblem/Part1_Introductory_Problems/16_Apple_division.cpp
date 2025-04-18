#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long ;

ll solve(int index, vector<ll> arr , ll sum1 , ll sum2 , int N ){
    if( index == N ){
        return abs(sum1-sum2);
    }

    ll choose = solve (index+1 , arr , sum1+arr[index] , sum2 , N);
    ll not_choose = solve (index+1 , arr , sum1 , sum2+arr[index] , N );
    return min(choose , not_choose);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    vector<ll> a ;
    int n ;
    cin >> n ;
    ll sum = 0 ;
    for(int i = 0 ; i < n ; i++ ){
        ll x ;
        cin >> x ;
        a.push_back(x);
        sum += x ;
    }
    ll ans = solve(0,a,0,0,n);
    cout << ans << endl;
}