#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);
    int n ;
    unordered_set<int> C_num = {2465, 1729, 15841, 46657, 2821, 62745, 63973, 6601, 52633, 8911, 1105, 561, 41041, 10585, 29341};
    while(cin >> n , n ){
        if(C_num.count(n)){
            cout << "The number "<< n << " is a Carmichael number." << endl;
        }
        else{
            cout << n << " is normal." << endl;
        }
    }
}
// AC , 0.120 sec 