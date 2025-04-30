#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<unsigned long long int > factorial;
    factorial.clear();
    factorial.push_back(1);
    int min = 0 ;
    bool state = false ;
    
    while( factorial.back() <= 6227020800 ){
        factorial.push_back(factorial.size() * factorial.back());
        if(factorial.back() > 10000 && !state){
            min = factorial.size()-1 ;
            state = true;
        }
    }
    int n ;
    while(cin >> n ){
        if((n < 0 && n % 2 == 0 ) || (n >= 0 && n < min) ){
            cout << "Underflow!" << endl;
        }
        else if ( (n < 0 && n & 1 ) || (n >= 0 && n >= (int)factorial.size()-1) ){
            cout << "Overflow!" << endl;
        }
        else{
            cout << factorial[n] << endl;
        }
    }
}