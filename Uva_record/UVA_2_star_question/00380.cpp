#include<bits/stdc++.h>
using namespace std;

int dfs(int source , int time , unordered_map<int,map<int,pair<int,int>>>& forwards , unordered_set<int>&visited){
    if(visited.count(source)) return 9999 ; // 形成環
    visited.insert(source);

    if(forwards[source].count(time)){   // 剛好在時間上 
        return dfs(forwards[source][time].second , time , forwards , visited);
    }
    auto it = forwards[source].lower_bound(time);   // 找到大於或等於 time 的位置 

    if(it != forwards[source].begin()){ // 前一個會比time 還小
        --it ; 
        if(it->first + (it->second).first >= time ){    // 如果 前一個的time + 他的duration 比time還大，表示可以轉接
            return dfs((it->second).second, time, forwards, visited);
        }
    }
    return source ;
}

int main(){
    int n ;
    cin >> n ;
    int kase = 0 ;
    cout << "CALL FORWARDING OUTPUT" << endl;
    int s , t , d , e;
    while(n--){
        unordered_map<int,map<int,pair<int,int>>> forwards ; 
        while( cin >> s , s ){
            cin >> t >> d >> e;
            forwards[s][t] = {d,e};
        }
        cout << "SYSTEM " << ++kase << endl;
        while(cin >> t , t != 9000 ){
            cin >> s ;
            unordered_set<int> visited;
            int res = dfs(s,t,forwards, visited);
            printf("AT %04d CALL TO %04d RINGS %04d\n", t, s , res);
        }
    }
    cout << "END OF OUTPUT" << endl;
}
// 參考資料 : https://github.com/KHvic/uva-online-judge/blob/master/380-Call%20Forwarding.cpp
/*
2
1111 0100 0200 2222
1111 0301 0500 4444
2222 0200 0200 3333
3333 0250 1000 1111
7777 1000 2000 7777
0000
0050 1111
0150 1111
0200 1111
0225 2222
0270 1111
0320 1111
0320 3333
0900 3000
1250 3333
1250 7777
9000
0000
3000 1111
9000
*/