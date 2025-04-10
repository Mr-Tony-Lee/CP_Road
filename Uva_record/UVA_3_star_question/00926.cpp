#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    int C ; 
    cin >> C ;
    while(C--){
        int line;
        cin >> line ;
        vector<vector<vector<int>>> dp(line+1, vector<vector<int>>(line+1,vector<int>(2,-1)));
        // dp[i][j][0] 上方的來源 , dp[i][j][1] 左方的來源 , total 就是 dp[i][j][0] + dp[i][j][1]
        int start_x , start_y ;
        int end_x , end_y ;
        cin >> start_x >> start_y ;
        cin >> end_x >> end_y ; 
        int W ;
        cin >> W ;
        while(W--){
            int Px , Py;
            char dir ;
            cin >> Px >> Py ;
            cin.ignore();
            dir = getchar() ; 
            if(dir == 'S'){ // 左方
                dp[Px][Py][1] = 0 ;
            }
            else if ( dir == 'W') { // 上方
                dp[Px][Py][0] = 0 ;
            }
            else if ( dir == 'N'){  // 右方
                dp[Px][Py+1][1] = 0 ;
            }
            else{   // 下方
                dp[Px+1][Py][0] = 0 ; 
            }
        }
        dp[start_x][start_y][0] = 1 ;   // 起始點 ， 隨便設定，總和是 1 就好了
        dp[start_x][start_y][1] = 0 ;
        for(int i = start_x+1 ; i <= line ; i++ ) { // 跟起始點同一行
            if(dp[i][start_y][0] == -1 ) {
                dp[i][start_y][0] = dp[i-1][start_y][0] + dp[i-1][start_y][1];
            }
            dp[i][start_y][1] = 0 ; 
        }
        for(int j = start_y+1 ; j <= line ; j++ ) { // 跟起始點同一列
            dp[start_x][j][0] = 0 ;
            if(dp[start_x][j][1] == -1 ) {
                dp[start_x][j][1] = dp[start_x][j-1][0] + dp[start_x][j-1][1];
            }
        }
        for(int i = start_x + 1 ; i <= line ; i++ ){    // 剩下的內部，其實更快的方法是跑到 end_x 跟 end_y 就好，因為題目保證有一條路
            for(int j = start_y + 1 ; j <= line ; j++ ){
                if(dp[i][j][0] == -1 ){
                    dp[i][j][0] = dp[i-1][j][0]+dp[i-1][j][1];
                }
                if(dp[i][j][1] == -1 ){
                    dp[i][j][1] = dp[i][j-1][0] + dp[i][j-1][1];
                }
            }
        }
        // debuging 
        // for(int i = start_x ; i <= line ; i++ ){
        //     for(int j = start_y ; j <= line ; j++ ){
        //         cout << dp[i][j][0] + dp[i][j][1] << " ";
        //     }
        //     cout << endl;
        // }
        int ans = dp[end_x][end_y][0] + dp[end_x][end_y][1];
        cout << ans << endl;
    }
}
/*
    解題說明 : 根據來源去算此格的走法， 把兩個方向的來源分別用陣列存起來(dp[i][j][0] && dp[i][j][1] )，
    然後把施工方向的來源設為0 ， 也就是如果有施工，就沒有來源。最後去dp出每個來源的總和。
*/
/*
    2
    3
    1 1
    3 3
    2
    2 3 S
    2 2 W
*/