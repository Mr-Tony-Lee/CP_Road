#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n ;
    cin >> n ;

    int a , b , c , d ;
    double e ; 
    double U = 1.0 * n /30 ;
    a = U / 100 ;
    b = (U - a*100) / 10 ;
    c = (U - a*100 - b*10 );
    d = (U - a*100 - b*10 - c ) * 10 ; 
    e = 1.0*(U - a*100 - b*10 - c - d* 0.1 )*30;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "e = " << round(e) << endl;

}