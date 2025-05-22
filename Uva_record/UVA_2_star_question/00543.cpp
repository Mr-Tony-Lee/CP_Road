#include<bits/stdc++.h>
using namespace std;
#define N 1000000
int main(){
    set<int> prime;
    prime.insert(2);
    bool v[N] = {};
    for(int i = 3 ; i < N ; i += 2 ){
        if(!v[i]){
            prime.insert(i);
            for(int j = 2*i ; j < N ; j += i ){
                v[j] = true;
            }
        }
    }
    // 78498 
    int n ;
    while(cin >> n){
        if( n == 0 ) break;
        int a = 0 , b = 0 ;
        for(auto& iter : prime){
            if(prime.count(n - iter)){
                a = iter ;
                b = n-iter;
                break;
            }
        }
        if( a && b ){
            printf("%d = %d + %d\n", n , a , b);
        }
        else{
            cout << "Goldbach's conjecture is wrong." << endl;
        }
    }
}