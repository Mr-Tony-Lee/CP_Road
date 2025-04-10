#include<iostream>
using namespace std;

int S (int n , int m  ){
    if ( m > n || m == 0   ){
        return 0 ;
    }
    else if ( m == n ){
        return 1 ; 
    }
    else{
        return m*S(n-1,m) + S(n-1,m-1);
    } 
}


int main(){
    int times ;
    cin >> times ;
    while(times--){
        int n , m ; 
        cin >> n >> m ;
        cout << S(n , m) % 2 << endl;
    }
}
// TLE for 1118 ;
/* 
#include<stdio.h>
#include<iostream>

using namespace std;

// use the array 1000000000 by 1000000000 is impossible to finish in 3 seconds
// we have to use the properties of Stirling Numbers to determine the remainder
int main(){

	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << (((n - m) & ((m - 1) / 2)) == 0) << endl;
	}
	return 0;
}
*/