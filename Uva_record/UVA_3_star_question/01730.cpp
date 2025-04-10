// (1,2) , (1,3) , (1,2,4) , (1,5) ,(1,2,3,6) , (1,7) , (1,2,4,8) , (1,3,9) , (1,2,5,10)
// 3 , 4 , 7 , 6 , 12 , 8 , 15, 13, 18,
// 20 , 20 , 28,18 -> 86 

#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    cin.tie(0); cout.tie(0) ; ios::sync_with_stdio(0);
    int n ;
    // r log N 
    while(cin >> n , n ){
        int ans = 0 ;
        // factor k , time = n/k
        
        // for(int i = 1 ; i <= n ; i++ ){
        //     if( (n / i) != time ){
        //         ans += now*time;
        //         time = n/i;
        //         now = i ;
        //     }
        //     else{
        //         now += i ; 
        //     }
        // }
        // ans += now*time;


        // 因數有出現特定頻率的區間
        // l 是 左區間 ， r 是右區間
        // t 是頻率
        int l = 0 , r = 0  , t ; 
        while( r != n ){
            l = r + 1 ;   
            t = n / l ; 
            r = n / t;
            ans += (r-l+1)*(r+l) / 2 * t  ;
        }
        cout << ans-1 << endl;
    }
    return 0 ;
}