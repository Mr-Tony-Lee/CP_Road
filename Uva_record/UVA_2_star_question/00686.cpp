#include<bits/stdc++.h>
using namespace std;

int N = 1 << 15;

int main(){
    int n ; 
    set<int> prime;
    vector<bool> table(1<<15 ,false);
    for(int i = 2 ; i < N ; i++ ){
        if(!table[i]){
            prime.insert(i);
            for(int j = 2*i ; j < N ; j += i ){
                table[j] = true ;
            }
        }
    }
    while(cin >> n , n ){
        int ans = 0 ;
        for(auto& num:prime){
            if(num > n/2){
                break;
            }
            if(prime.count(n-num)){
                ans ++ ;
            }
        }
        cout << ans << endl;
    }
}