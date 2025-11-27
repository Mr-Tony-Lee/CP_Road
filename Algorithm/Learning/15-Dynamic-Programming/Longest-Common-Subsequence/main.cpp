#include<bits/stdc++.h>
using namespace std;

void LCS(const string & str1, const string & str2){
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++ ){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1; // 字符相同，LCS長度加1
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // 取較長的LCS長度
            }
        }
    }
    
    cout << "Length of Longest Common Subsequence between \"" << str1 << "\" and \"" << str2 << "\" is: " << dp[n][m] << endl;

}

int main(){
    string str1 = "intention";
    string str2 = "execution";
}