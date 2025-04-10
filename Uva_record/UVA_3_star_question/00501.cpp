#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) ; cout.tie(0); ios::sync_with_stdio(false);
    int k ; 
    cin >> k ;
    int t = 1; 
    while(k--){
        int m , n ; 
        cin >> m >> n ;
        vector<int> A(m,0) ;
        vector<int> u(n,0); 
        for(int i = 0 ; i < m ; i++ ){
            cin >> A[i];
        }
        for(int i = 0 ; i < n ; i++ ){
            cin >> u[i];
        }
        int now_min_index = 0 ;
        vector<int> arr ;
        if(t != 1 ) cout << endl;
        for(int i = 0 ; i < m ; i++ ){
            arr.insert(lower_bound(arr.begin(),arr.end(),A[i]),A[i]);   // 找到合適的位置插入(add) ，插入完應該要是遞增的order 
            for(int j = 0 ; j < n ; j++ ){
                if(arr.size() == u[j]){ // 去查找是否有跟現在size一樣的 , 有就 get 
                    cout << arr[now_min_index++] << endl;
                }
            }
        }
        t++;
    }
}