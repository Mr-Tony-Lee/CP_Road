#include<bits/stdc++.h>
using namespace std;

void EditDistance(const string& str1, const string& str2){
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 0 ; i <= n ; i++ ){
        dp[i][0] = i; // 刪除操作
    }
    for(int j = 0 ; j <= m ; j++ ){
        dp[0][j] = j; // 插入操作
    }

    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++ ){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1]; // 字符相同，不需要操作
            }
            else{
                dp[i][j] = min({ dp[i-1][j] + 1,    // 刪除
                                 dp[i][j-1] + 1,    // 插入
                                 dp[i-1][j-1] + 1   // 替換
                               });
            }
        }
    }
    
    cout << "Edit Distance between \"" << str1 << "\" and \"" << str2 << "\" is: " << dp[n][m] << endl;
}

int main(){
    string str1 = "intention";
    string str2 = "execution";
    EditDistance(str1, str2);
}