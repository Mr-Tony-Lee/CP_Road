第一題:
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


第二題:

#include<iostream>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < i ; j++){
            cout << " ";
        }
        for(int j = 0 ; j < n-i ; j++ ){
            cout << j+1 ;
        }
        for(int j = n-i-1 ; j >= 1 ; j-- ){
            cout << j ;
        }
        cout << endl;
    }
}