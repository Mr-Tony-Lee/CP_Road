#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

int main(){
    int S ; 
    map<int,int> array;
    for(int i = 1000 ; i >= 1 ; i-- ){
        int sum = 0 ; 
        for(int j = 1 ; j <= i ; j++ ){
            if( i % j == 0 ){
                sum += j ; 
            }
        }
        array[i] = sum ; 
    }
    int count = 1 ; 
    while(cin >> S && S ){
        bool flag = true;
        for(auto iter = array.rbegin() ; iter != array.rend() ; iter++ ){
            if(iter->second == S ){
                cout << "Case " << count << ": " << iter->first << endl;
                flag = !flag;
                break;
            }
        }      
        if(flag)  cout << "Case " << count << ": " << -1 << endl;      
        ++count;
    }
}
// Accepted Uva 