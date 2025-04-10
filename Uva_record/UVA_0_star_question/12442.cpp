#include <bits/stdc++.h>
using namespace std;
#define MAXN 50020

vector<int> arr[MAXN];
int vis[MAXN] , flag[MAXN];
int cnt = 0 ;

void dfs (int x ){
    if(vis[x]) return ; 
    vis[x] = 1 ;

    for(auto v:arr[x]){
        dfs(v);
        cnt++ ;
    }
    vis[x] = 0 ;
    flag[x] = 1 ;
}


int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int n;
        cin >> n;
        for(int i = 1 ; i <= n ; i++ ) arr[i].clear();
        
        for(int i = 1 ; i <= n ; i++ ){
            int u , v ;
            cin >> u >> v ;
            arr[u].push_back(v);
        }
        memset(vis , 0 , sizeof(vis));
        memset(flag , 0 , sizeof(flag));
        int ans = 0 , mc = 0 ; // ans , max_count 
        for(int i = 1 ; i <= n ; i++ ){
            if(flag[i]) continue;
            cnt = 0 ; 
            dfs(i);
            if(cnt > mc ){
                ans = i ;
                mc = cnt ;
            }
        }
        cout << "Case " << k << ": " << ans << endl;
    }
}
// 參考資料 : https://theriseofdavid.github.io/2021/09/06/UVa/UVa12442/
// 因為此題只會有一個路徑，我們就計算從此起點走到最後的距離是多少，因為有環，所以走回起點也算結束
// flag 用來處存這條路徑走過的地點， 假設現在 5 -> 1 -> 2 -> 3 -> 4 
// 在跑 dfs(1) 的時候， 會走過 1 2 3 4 ， 但不會走到 5， 但在跑 2 3 4 的時候，因為1 已經走過一次了，我們不希望再走一次，所以用 flag 儲存是否處理過
// 因為我們只care 最大的距離，所以 2,3,4 不走也沒關係
// 然後 visit 主要紀錄 是否有環 ， 所以用 visit儲存走過的點， 遇到環的話 ， 起點visit是 1 ，就會 return 
/*
3
3
1 2
2 3
3 1
4
1 2
2 1
4 3
3 2
5
1 2
2 1
5 3
3 4
4 5
*/