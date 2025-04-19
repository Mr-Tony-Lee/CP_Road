#include<bits/stdc++.h>
using namespace std;

int N = 1300000;

int main(){
    vector<int> prime;
    vector<bool> table(N,false);
    prime.push_back(2);
    for(int i = 3 ; i < N ; i += 2 ){
        if(!table[i]){
            prime.push_back(i);
            for(int j = 2*i ; j < N ; j += i ){
                table[j] = true;
            }
        }
    }
    int n ;
    while(cin >> n , n ){
        if(find(prime.begin(),prime.end() , n ) == prime.end()){
            auto higher = upper_bound(prime.begin(),prime.end() , n );
            auto lower = higher;
            lower--;
            cout << *higher - *lower << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
}