#include<bits/stdc++.h>
using namespace std;

double myabs(double x ){
    if(x < 0 ) return -x ;
    return x ;
}

int main(){
    int t ;
    cin >> t ;
    while(t--){
        double mc , tp ;
        cin >> mc >> tp ;
        int n ;
        cin >> n ;
        vector<vector<pair<double,double>>> dp (n , vector<pair<double,double>>(n,{0,0}));
        vector<pair<double,double>> p ;
        for(int i = 0 ; i < n ; i++ ){
            double v , t ;
            cin >> v >> t ;
            p.push_back({v,t});
            dp[i][i] = {v,t};
        }
        double mavg = 1e9;
        pair<int,int> ans ; 
        ans = {-1,-1};
        for(int i = 0 ; i < n ; i++ ){
            for(int j = i ; j < n ; j++ ){
                if( j != i ) dp[i][j] = {dp[i][j-1].first + p[j].first , dp[i][j-1].second*dp[i][j-1].first/(dp[i][j-1].first + p[j].first)  + p[j].first*p[j].second/(dp[i][j-1].first + p[j].first)};
                if(dp[i][j].first > mc ) break;
                double avg = dp[i][j].second;
                if(dp[i][j].first >= mc/2 && myabs(avg-tp) <= 5 && myabs(avg-tp) < mavg){
                    ans = {i,j};
                    mavg = myabs(avg-tp);
                }
            }
        }
        if(ans.first != -1 ) cout << ans.first << " " << ans.second << endl;
        else cout << "Not possible" << endl;
    }
}
/*
2
615 11
15
24 18
25 5
74 4
80 5
75 3
96 2
53 6
25 24
74 20
97 20
76 3
14 16
8 3
21 14
82 18
100 20
3
10 20
66 40
5 100
*/