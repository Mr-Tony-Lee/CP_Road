#include<iostream>
using namespace std;
int main(){
    int n ; 
    int count_zero = 0 ; 
    while(cin >> n ){
        if( n == 1 ) break;
        if( n == 0 ) count_zero++;
    }
    cout << count_zero << endl;
}