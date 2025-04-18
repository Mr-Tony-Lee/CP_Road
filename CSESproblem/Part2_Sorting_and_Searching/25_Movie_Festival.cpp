#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> a , pair<int,int> b){
    return a.second < b.second;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n ;
    cin >> n;
    vector<pair<int,int>> movie ;
    for(int i = 0 ; i < n ; i++ ){
        int a , b ;
        cin >> a >> b ;
        movie.push_back(make_pair(a,b));
    }
    sort(movie.begin(), movie.end() , compare);
    int now_right = 0;
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++ ){  //每次都選結束時間最快的，就能看最多場。
        if ( movie[i].first >= now_right){
            now_right = movie[i].second;
            ans++;
        }
    }
    cout << ans << endl;
}