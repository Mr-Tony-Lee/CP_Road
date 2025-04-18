#include<iostream>
#include<cmath>
using namespace std;
using ll = long long ;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n ;
    cin >> n ;
    ll count_5 = 0 ;
    for(int i = 5 ; i <= n ; i += 5){
        int k = i ; 
        count_5 ++ ;
        while( !((k/5) % 5 )){
            k /= 5 ;
            count_5++;
        }
    }

    // ans is min(the number of 2 , the number of 5 );
    cout << count_5 << endl;
}