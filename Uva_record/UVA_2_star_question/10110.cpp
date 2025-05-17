#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n ;
    while(cin >> n , n ){
        long long int sn = sqrt(n);
        if(sn * sn == n ){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
}