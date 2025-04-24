#include<bits/stdc++.h>
using namespace std;


int A[1000005] , B[1000005];


int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);

    int t ;
    cin >> t;
    while(t--){
        int m ;
        cin >> m;
        for(int i = 0 ; i < m ; i++){
            cin >> A[i] >> B[i];
        }
        bool carry = false;
        for(int i = m-1 ; i >= 0 ; --i){
            if(carry){
                carry = ((A[i] + B[i] + 1) >= 10 ) ;
                A[i] = (A[i] + B[i] + 1) % 10 ;
                
                
            }
            else{
                carry = (( A[i] + B[i] ) >= 10) ;
                A[i] = ( A[i] + B[i] ) % 10 ;
            }
        }
        if(carry){
            cout << "1" ;
        }
        for(int i = 0 ; i < m ; i++ ){
            cout << A[i];
        }
        cout << endl;
        
        if(t) cout << endl;
    }
}
/*

2
4
0 4
4 2
6 8
3 7 
3
3 0
7 9
2 8
*/