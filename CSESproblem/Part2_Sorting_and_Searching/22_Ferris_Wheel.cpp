#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n , x ;
    vector<int> every_child ;
    cin >> n >> x ;
    for(int i = 0 ; i < n ; i++ ){
        int p ;
        cin >> p ;
        every_child.push_back(p);
    }
    sort(every_child.begin() , every_child.end());
    int index_f = 0 , index_b = every_child.size()-1;
    int ans = 0 ;
    while(index_f <= index_b ){
        if(index_f == index_b ){
            ans++;
            break;
        }
        if(every_child[index_b] + every_child[index_f] > x ){
            ans++;
            index_b -- ;
        }
        else{
            ans++;
            index_b--;
            index_f++;
        }
    }
    cout << ans << endl;
}