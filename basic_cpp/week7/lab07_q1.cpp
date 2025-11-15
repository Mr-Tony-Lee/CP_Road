#include<iostream>
using namespace std; 

int reverse ( int n ){
    int rev = 0 ;
    while( n > 0 ){
        rev = rev * 10 + n % 10 ;
        n = n / 10 ;
    }
    return rev ;
}

bool isPalindrome ( int n ){
    return n == reverse(n) ;
}

int main(){
    int n ;
    cin >> n ;
    if( isPalindrome(n) ){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}