#include<iostream>
#include<cmath>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    double n ; 
    cin >> n ;
    if ( n == 1 ){
        cout << 1 << endl;
        return 0;
    }
    else if( 2 <= n && n <= 3 ){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    int x = 2 ;
    for(int i = 1 ; i <= n ; i ++ ){
        if( x > n ){
            x = 1 ;
        }
        cout << x << " ";
        x+= 2 ;
    }
    cout << endl;
}