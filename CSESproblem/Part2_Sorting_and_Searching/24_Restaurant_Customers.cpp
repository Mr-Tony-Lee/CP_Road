#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>    
using namespace std;

bool compare(pair<int,int> a , pair<int,int> b){
    return a.first < b.first ; 
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n ;
    cin >> n ;
    vector<pair<int,int>> all;
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++ ){
        int a , b ;
        cin >> a >> b ;
        all.push_back(make_pair(a,1));
        all.push_back(make_pair(b,-1));
    }
    sort(all.begin() , all.end() );
    int cur = 0 ;
    for ( auto& iter: all ){
        cur += iter.second;
        ans = max(ans,cur);
    }
    cout << ans << endl;
}