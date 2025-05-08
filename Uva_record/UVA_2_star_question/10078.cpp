#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int cross (P o , P a , P b ){
    return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first);
}

int main(){
    int n ;
    while(cin >> n , n ){
        vector<P> arr(100);
        for(int i = 0 ; i < n ; i++ ){
            cin >> arr[i].first >> arr[i].second;
        }
        arr[n] = arr[0] , arr[n+1] = arr[1];
        bool ans = false;
        if(cross(arr[0],arr[1],arr[2]) >= 0 ){
            for(int i = 0 ; i < n ; i++ ){
                if( cross(arr[i],arr[i+1],arr[i+2]) < 0 ){
                    ans = true; 
                    break;
                } 
            }
        }
        else{
            for(int i = 0; i < n ; i++ ){
                if(cross(arr[i],arr[i+1],arr[i+2]) > 0 ){
                    ans = true;
                    break;
                } 
            }
        }
        if(ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}