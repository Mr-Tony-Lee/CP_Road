#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n ;
    while( cin >> n ){
        int ans = 0 ; 
        vector<int> arr(n,0);
        for(int i = 0 ; i < n ; i++ ){
            cin >> arr[i] ;
        }
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < n-i-1 ; j++ ){
                if(arr[j] > arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    ans ++ ;
                }
            }
        }
        cout << "Minimum exchange operations : " << ans << endl;
    }
}