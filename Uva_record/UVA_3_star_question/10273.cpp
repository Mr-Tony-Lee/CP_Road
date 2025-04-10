#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0) ; ios::sync_with_stdio(false);
    int T ;
    cin >> T ;
    while(T--){
        int N ;
        cin >> N ;
        int total_days = 1 ; 
        vector<vector<int>> cow_cycle ;
        for(int i = 0 ; i < N ; i++ ){
            int Ti ;
            cin >> Ti ;
            vector<int> each(Ti) ;
            total_days = (total_days / __gcd(total_days, Ti)) * Ti ; 
            for(int j = 0 ; j < Ti ; j++ ){
                cin >> each[j];
            }
            cow_cycle.push_back(each);
        }
        vector<bool> eaten(N , false);
        int eaten_day = -1 ; // be_eaten days 
        for(int i = 0 ; i < eaten_day + total_days + 1 ; i++ ){
            int cow = -1 ;
            bool alive = false ;
            for(int j = 0 ; j < N ; j++ ){
                if(eaten[j] ) continue;
                // 線性 找 min  
                if(cow == -1 ){
                    cow = j ;
                    continue;
                }
                int cur_cow = cow_cycle[j][i%cow_cycle[j].size()];
                int min_cow = cow_cycle[cow][i%cow_cycle[cow].size()];
                if(cur_cow == min_cow ){
                    alive = true ;
                    continue;
                }
                if(cur_cow < min_cow){
                    cow = j;
                    alive = false;
                }
            }
            if(!alive && cow != -1 ){
                eaten[cow] = true ;
                eaten_day = i ;
                total_days = 1 ;
                for(int j = 0 ; j < N; j++){
                    if(eaten[j]) continue;
                    total_days = (total_days / __gcd(total_days,int(cow_cycle[j].size()))) * cow_cycle[j].size();
                }
            }
        }
        
        int alive_num = 0 ;
        for(int i = 0 ; i < N ; i++ ){
            alive_num += !eaten[i];
        }
        cout << alive_num << " " << eaten_day + 1 << endl;
    }
}

/*
1
4
4 7 1 2 9
1 2
2 7 1
1 2
*/