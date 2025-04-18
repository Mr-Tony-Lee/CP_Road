#include<iostream>
#include<vector>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n ; 
    cin >> n ;
    int ans = 1 ;
    
    //先把每個數字出現的位置放到一個vector中
    vector<int> indices(n+1);
    for(int i = 0 ; i < n ; i++ ){
        int x ;
        cin >> x ;
        indices[x] = i; 
    }

    // 如果數字出現的位置 比後面那個數字還晚，那就要多一round 
    for(int num = 1 ; num < n ; num++ ){
        if(indices[num+1] < indices[num]){
            ans++;
        }
    }
    cout << ans << endl;
}
