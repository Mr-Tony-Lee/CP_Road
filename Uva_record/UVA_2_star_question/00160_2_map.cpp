#include<iostream>
#include<map>
#include<cmath>
#include<iomanip>
using namespace std;
int prime[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
void solve(map<int,int>& a , int N ){
    int bound = sqrt(N);
    int i = 0 ; 
    while( prime[i] <= bound ){
        if(N % prime[i] == 0 ){
            N /= prime[i] ;
            a[prime[i]] ++ ;
        }
        else{
            i++ ; 
        }
        bound = sqrt(N);
    }
    if( N != 1 ){
        a[N]++;
    }
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N ;
    while(cin >> N && N ){
        map<int,int> fact;
        for(int i = N ; i >= 2 ; i--){
            solve(fact,i);
        }
        int count = 1 ; 
        cout << setw(3) << N ;
        cout << "! =" ;
        for(auto& iter:fact){
            if(count % 16 == 0 ){
                cout << endl;
                cout << "      ";
            }
            cout << setw(3) << iter.second ;
            count++;
        }
        cout << endl;
    }
}