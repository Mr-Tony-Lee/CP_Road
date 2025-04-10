#include<bits/stdc++.h>
using namespace std;
#define int long long 
using llu = unsigned int ;


llu gcd(llu a , llu b ){
    if( b == 0 ) return a ;
    
    if ( a > b ){
        return gcd(b , a%b);
    }
    else {
        return gcd(a , b%a);
    }
}

void fraction(llu x , llu y ){
    if(x % y == 0 ) cout << x/y << endl;
    else{
        cout << x/gcd(x,y) << "/" << y/gcd(x,y) << endl;
    }
}

int32_t main(){
    llu v1 , d1 , v2 , d2 , t1 , t2 ;
    int count = 1 ;
    while(cin >> v1 >> d1 >> v2 >> d2 && (v1 || d1 || v2 || d2 )){
        t1 = v1 * d2;
        t2 = v2 * d1;
        cout << "Case #" << count++ << ": ";
        if (t2 > t1 ){
            cout << "You owe me a beer!" << endl;
        }
        else{
            cout << "No beer for the captain." << endl;
        }
        cout << "Avg. arrival time: ";
        fraction(v1*d2+v2*d1 , 2*v1*v2);
    }
}
// Accepted Uva 