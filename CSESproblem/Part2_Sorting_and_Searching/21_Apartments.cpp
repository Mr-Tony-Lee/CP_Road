#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n , m , k ;     
    cin >> n >> m >> k;
    int ans = 0 ;
    vector<int> a ;
    vector<int> b ;
    for(int i = 0 ; i < n ; i++ ){
        int an ; 
        cin >> an ;
        a.push_back(an);
    }
    for(int i = 0 ; i < m ; i++ ){
        int bm;
        cin >> bm ;
        b.push_back(bm);
    }
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    int now = 0 ;
    for(int i = 0 ; i < (int)a.size() ; i++ ){
        bool flag = false;
        for(int j = now ; j < (int)b.size() ; j++ ){
            if(a[i] - k <= b[j] && b[j] <= a[i]+k ){
                flag = true ;
                now = j + 1;
                break ;
            }
            else if ( b[j] > a[i] + k){
                now = j;
                break;
            }
        }
        if(flag) ans++;
    }
    cout << ans << endl;
}