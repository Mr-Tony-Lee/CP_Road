#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n ;
    while(n--){
        int N ;
        cin >> N ;
        if( N == 1 ){
            cout << 1 << endl;
            continue;
        }
        vector<int> ans ;
        while( N > 1 ){
            bool state = true;
            for(int i = 9 ; i >= 2 ; i--){
                if( N % i == 0 ){
                    state = false;
                    ans.push_back(i);
                    N /= i ;
                    break;
                }
            }
            if(state) break;
        }
        
        if(ans.empty() || N != 1 ){
            cout << "-1" << endl;
        }
        else if ( N == 1 ) {
            sort(ans.begin() , ans.end());
            for(auto& num:ans){
                cout << num ;
            }
            cout << endl;
        }
    }
}