#include<iostream>
using namespace std;
using ll = long long ;
int dx[4] = {-2, 2, -1 , 1};
int dy[4] = {1 , 1,  2 , 2 };
ll C ( int n , int r  ){
    ll ans = 1;
    for(int i = n ; i > n-r ; i--){
        ans *= i ;
    }
    for(int i = r ; i > 1 ; i--){
        ans /= i ;
    }
    return ans ;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x;
    cin >> x ;
    for(ll n = 1 ; n <= x ; n++){
        ll all = C(n*n,2);
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++ ){
            int temp_cross_1 = 0 ;
            for (int k = 0 ; k < 2 ; k++ ){
                if(i + dx[k] >= 0 && i + dx[k] < n ){
                    temp_cross_1++;
                }
            }
            temp_cross_1 *= (n-1);
            int temp_cross_2 = 0 ;
            for(int k = 2 ; k < 4 ; k++ ){
                if(i + dx[k] >= 0 && i + dx[k] < n && n > 1 ){
                    temp_cross_2++;
                }
            }
            temp_cross_2 *= (n-2);
            ans += (temp_cross_1 + temp_cross_2);
        }
        cout << all-ans << endl;
    }
}