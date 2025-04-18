#include<bits/stdc++.h>
using namespace std;

int N = 1000000;

int mod(int x , int y ){
    while(x < 0 ){
        x += y ;
    }
    return x % y ; 
}

int main(){
    set<int> all ; 
    for(int i = 100 ; i <= N ; i++ ){
        if( i % 2 == 0 ) continue;
        vector<int> digit ; 
        int ic = i ; 
        bool even = false ;
        while( ic > 0 ){
            digit.push_back(ic % 10);
            if((ic % 10) % 2 == 0 ) even = true;
            ic /= 10 ; 
        }
        if(even) continue;
        int cnt = 0 ;
        for(int k = (int)digit.size()-1 ; k >= 0 ; k--){
            int number = 0 ;     
            for(int j = 0 ; j < (int)digit.size() ; j++ ){
                number = number * 10 + digit[mod(k-j,digit.size())];
            }
            bool state = 0 ;
            for(int m = 3 ; m <= sqrt(number) ; m += 2 ){
                if(number % m == 0 ) state = true;
            }
            if(state ) break;
            else cnt++;
        }
        if(cnt == (int)digit.size()){
            all.insert(i);
        }
    }
    int lower , higher;
    while( cin >> lower ){
        if ( lower == -1 ) break;
        cin >> higher ;
        int count = 0 ;
        for(auto iter = all.lower_bound(lower) ; iter != all.upper_bound(higher) ; iter++){
            count++;
        }
        if(count == 0 ){
            cout << "No Circular Primes." << endl;
        }
        else{
            if(count == 1 ){
                cout << count << " Circular Prime." << endl;    
            }
            else{
                cout << count << " Circular Primes." << endl;
            }
        }
    }
}