#include<bits/stdc++.h>
using namespace std;
#define int long long 

int dp[55][55][55];

int solve(int n , int k , int m ){
    if(dp[n][k][m] != -1 ) return dp[n][k][m];
    if( n == 0 ){   // 如果 n == 0 了 代表沒有bar了，那 k 應該也要等於 0 這樣才有解，否則就回傳0
        if(k == 0) {
            return 1 ;
        }
        else {
            return 0 ; 
        }
    }
    if( k == 1 ){   // 如果 k == 1，代表剩下最後一組要分，那這組不能超過 m，所以 n <= m 就代表有解，否則無解
        if(n <= m ){
            return 1 ;
        }
        else{
            return 0 ;
        }
    }
    int left = 0 ;
    for(int x = 1 ; x <= min(n,m) ; x++ ){  // 把問題拆分， 因為第一個一定是 1 那下一個一定是 0 在下一個肯定又是 1
        left += solve(n-x,k-1,m);   // 每次都慢慢地變小去看後面的組合，最後加起來
    }
    dp[n][k][m] = left ;
    return dp[n][k][m];
}

int32_t main(){
    memset(dp , -1 , sizeof(dp));
    int n , k , m ;
    while(cin >> n >> k >> m ){
        cout << solve(n,k,m) << endl;
    }
}
/*
    解題說明 : 
        題目輸入 n , k , m ， 總共有n個bar，k就是有4個間隔，像1|00|111|0 ， m 就是一個間隔最多有3個1，最後要求出所有的組合數
        那我們可以用DP，設定第一個bar的長度是 x ， 而 x 一定小於 m 和 n ，然後去找出 dp[n-x][k-1][m]，因為已經用掉一個區間，所以 k-1。
        那最後要判斷終止條件，也就是當 n 是 0 的時候 或 和 k 是 1的時候，最後根據不同的條件，去設定回傳值，當 n 是 0 時，那 k 也一定要是 0
        當 k 是 1 時， n 一定要小於等於 m ，且 n 要大於 0 
*/
//  https://gdst.dev/posts/UVA-10721/index.html >> 參考資料
//  Accepted online judge   