#include<bits/stdc++.h>
using namespace std;

string input ;

char ans[20];

void dfs(int idx){
    if(idx == (int)input.size()){
        cout << ans << endl;
        return ;
    }
    // 把所有的字串往後移
    for(int i = idx ; i >= 1 ; --i ){
        ans[i] = ans[i-1];
    }
    
    for(int i = 0 ; i <= idx ; ++i ){
        ans[i] = input[idx];    // 現在在遞迴哪一個，就放入 idx 
        dfs(idx+1); // 向下遞迴 
        ans[i] = ans[i+1];  // 往前移一個
    }
}
/*

a
ba
cba -> output 
bba
bca -> output 
baa
bac -> output
ba

*/
int main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);
    int kase = 0 ;
    while(cin >> input ){
        if(kase)cout << endl;
        memset(ans,'\0',20);
        dfs(0);
        ++kase ;
    }
}

// 參考資料 : https://mypaper.pchome.com.tw/zerojudge/post/1322934227