#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    cin.tie(0); cout.tie(0) ; ios::sync_with_stdio(false);  
    int N ;
    while(cin >> N && ( N != -1 )){
        int now_male = 0  , now_female = 0 ;
        int total_male = 0 , total_female = 0 ;
        for(int i = 0 ; i < N ; i++ ){
            total_female = now_male;
            total_male = (now_male+now_female);
            // magic female
            total_male++;
            now_male = total_male;
            now_female = total_female;
        }
        cout << total_male << " " << total_male+total_female+1 << endl;
    }
}