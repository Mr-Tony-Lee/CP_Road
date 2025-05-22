#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>& s , int n , vector<int>& ans ){
    if( ans.size() == 6 ){
        for(int i = 0 ; i < 6 ; i++){
            if(!i) cout << ans[i];
            else{
                cout << " " << ans[i];
            }
        }
        cout << endl;
        return ;
    }
    for(int i = n ; i < s.size() ; i++ ){
        ans.push_back(s[i]);
        dfs(s,i+1, ans);
        ans.pop_back();
    }
    return ;
}

int main(){
    int n ;
    int kase = 0 ;
    while(cin >> n , n ){
        if(kase){
            cout << endl;
        }
        ++kase ;
        vector<int> s ;
        for(int i = 0 ; i < n ; i++ ){
            int x; 
            cin >> x ;
            s.push_back(x);
        }
        vector<int> ans ;
        dfs(s,0,ans );
    }
}