#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

int main(){
    int t;
    cin >> t ;
    while(t-- ){
        int n ; 
        cin >> n ;
        vector<int> array ;
        for(int i = 0 ; i < n ; i++){
            int x;
            cin >> x ;
            array.push_back(x);
        }
        int sum = 0 ;
        for(int i = 1 ; i < n ; i++ ){
            for(int j = 0 ; j < i ; j++ ){
                if(array[j] <= array[i]){
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }   
}

// Accepted Uva 