#include<bits/stdc++.h>
using namespace std;
#define int long long 

int solve(int n1 , int n5 , int n10 , int C , int target  ){
    int b = INT_MAX , c = INT_MAX , d = INT_MAX ;
    
    if ( n1 >= 3 && n5 >= 1 ){
        b = solve(n1-3 , n5-1 ,n10, C+1 , target) + 4 ;
    }
    if ( n5 >= 2 ){
        c = solve(n1+2 , n5-2 , n10 , C+1 , target ) + 2  ;
    }
    if ( n10 >= 1 ){
        d = solve(n1+2, n5 , n10-1 , C+1 , target ) + 1 ; 
    }
    if( C < target ){
        int a = (target-C) * 8 ;
        return min(a,min(b,min(c,d)));
    }
    else{
        return 0 ;
    }
    
}

int32_t main(){
    int t ;
    cin >> t ;
    while(t--){
        int c ;
        cin >> c;
        int n1 , n5 , n10 ; 
        cin >> n1 >> n5 >> n10 ; 
        int ans = solve(n1 , n5 , n10 , 0 , c);
        cout << ans << endl;
    }   
}
// 3 9 3 0 
// 9 3 0  -2 
// 11 1 0 
// 8 0 0 -4
// 0 0 0 -8 -> 14 