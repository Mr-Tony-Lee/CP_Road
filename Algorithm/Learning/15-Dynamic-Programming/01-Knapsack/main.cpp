#include<bits/stdc++.h>
using namespace std;
int capacity ;
// pair<int,int> -> val , wt 
vector<pair<int,int>> arr;

bool cmp(pair<int,int> a , pair<int,int> b ){
    if(a.second == b.second )
        return a.first < b.first ;
    return a.second < b.second ;
}

void solve(){
    sort(arr.begin(), arr.end() , cmp);
    int N = arr.size();
    vector<vector<int>> dp(N+1,vector<int>(capacity+1,0));
    for(int i = 1 ; i <= N ; i++ ){
        for(int j = 0 ; j <= capacity ; j++ ){
            if(j >= arr[i].second)
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i].second]+arr[i].first);
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << "DP -> Maximum value : " << dp[N][capacity] << endl;
    // answer is 62.
}

int main(){
    ifstream in;
    in.open("input.txt");
    in >> capacity;
    int v, w ;
    arr.push_back({0,0});
    while(in >> v >> w ){
        arr.push_back({v,w});
    }
    solve();
}