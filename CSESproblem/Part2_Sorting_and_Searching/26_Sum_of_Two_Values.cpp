#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
using ll = long long ;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n , x ;
    cin >> n >> x ;
    vector<pair<int,int>> a ;
    for(int i = 0 ; i < n ; i++ ){
        int ai ;
        cin >> ai ;
        a.push_back(make_pair(ai, i+1));
    }
    sort(a.begin() , a.end());
    int low = 0 , high = a.size()-1;
    while(low <= high){
        ll temp = a[low].first + a[high].first;
        if(temp == x ){
            break;
        }
        else if (temp > x ) {
            high--;
        }
        else{
            low++;
        }
    }
    if(low >= high){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << a[low].second << " " << a[high].second << endl;
    }
    
}