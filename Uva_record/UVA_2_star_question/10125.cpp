#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n ;
    while(cin >> n , n ){
        vector<int> S;
        for(int i = 0 ; i < n ; i++ ){
            int x; 
            cin >> x ;
            S.push_back(x);
        }
        sort(S.begin() , S.end());
        map<int,vector<pair<int,int>>> record;
        for(int i = 0 ; i < n-1 ; i++ ){
            for(int j = i+1 ; j < n ; j++ ){
                int sum = S[i]+S[j] ;
                record[sum].push_back({S[i],S[j]});
            }
        }
        int ans = 0 ; 
        int find = false; 
        for(int i = n-1 ; i >= 1 ; i-- ){
            for(int j = 0 ; j < i ; j++ ){
                int minus = S[i]- S[j];
                if(!record[minus].empty()){
                    for(int k = 0 ; k < record[minus].size() ; k++ ){
                        if(S[i] != record[minus][k].first && S[i] != record[minus][k].second 
                        && S[j] != record[minus][k].first && S[j] != record[minus][k].second){
                            ans = S[i];
                            find = true; 
                        }
                    }
                }
                if (find) break;
            }
            if (find) break;
        }
        if(find){
            cout << ans << endl;
        }
        else{
            cout << "no solution" << endl;
        }
    }
}