#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);
    int n ;
    int kase = 0 ;
    while(cin >> n , n ){

        if(kase++) cout << endl;
        vector<int> ori(n,0) ; 
        for(int i = 0 ; i < n; i ++){
            ori[i] = i+1;
        }
        int a ;
        while(cin >> a , a ){
            vector<int> arr(n,0);    
            arr[0] = a ;
            for(int i = 1 ; i < n ; i++ ){
                cin >> arr[i];
            }
            stack<int> s ;
            int now = 0 ;
            for(int i = 0 ; i < n ; i++){
                s.push(ori[i]);
                while(!s.empty() && s.top() == arr[now]){
                    now++;
                    s.pop();
                }
            }
            if(now == n ){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }
}