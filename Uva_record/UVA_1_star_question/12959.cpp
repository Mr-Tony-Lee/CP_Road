#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    int J , R ;
    while(cin >> J >> R && ( J || R )){
        map<int,int> score;
        for(int i = 0 ; i < R ; i++ ){
            for(int j = 0 ; j < J ; j++ ){
                int x ;
                cin >> x ;
                score[j] += x ;
            }
        }
        int max_s = 0  , max_idx = 0 ;
        for(auto iter:score ){
            if(iter.second >= max_s ){
                max_s = iter.second;
                max_idx = iter.first;
            }
        }
        cout << max_idx+1 << endl;
    }
}
// Accepted Uva 