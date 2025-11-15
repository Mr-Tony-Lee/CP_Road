#include<iostream>
using namespace std;
#define int long long 
int find_GCD(int a , int b ){
    if(b == 0 ){
        return a ;
    }
    if( a > b ){
        return find_GCD(b, a % b);
    }
    else{
        return find_GCD(a, b % a);
    }
}

int find_LCM(int a , int b ){
    int multi = a * b ;
    return multi / find_GCD(a,b);
}

int32_t main(){
    int a , b ;
    cin >> a >> b;
    if( a && b ){
        cout << find_LCM(a,b) << endl;
    }
    else{
        cout << 0 << endl;
    }
    
}