#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    vector<int> arr(10);
    for(int i = 0 ; i < 10 ; i++ ){
        cin >> arr[i];
    }
    int N ;
    cin >> N ;
    int min = INT_MAX ; 
    int ans_i , ans_j;
    for(int i = 0 ; i < 10 ; i++ ){
        for(int j = i+1 ; j < 10 ; j++ ){
            int distance = abs(arr[i]+arr[j]-N);
            if( distance < min ){
                ans_i = i ;
                ans_j = j ;
                min = distance;
            }
        }
    }
    cout << ans_i << " " << ans_j << endl;
}