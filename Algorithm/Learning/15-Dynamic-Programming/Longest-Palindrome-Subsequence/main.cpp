#include<bits/stdc++.h>
using namespace std;

void solve(string str1){
    // Longest Palindrome Subsequence
    int n = str1.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // i 是左界，j 是右界
    for(int i = n-1 ; i >= 0 ; i-- ){
        dp[i][i] = 1; // 單個字符是回文長度為1
        for(int j = i+1 ; j < n ; j++ ){
            if(str1[i] == str1[j]){
                dp[i][j] = dp[i+1][j-1] + 2; // 字符相同，回文長度加2
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]); // 取較長的回文長度
            }
        }
    }
    cout << "Length of Longest Palindrome Subsequence in \"" << str1 << "\" is: " << dp[0][n-1] << endl;
}

int main(){
    string str1 = "intention";
    solve(str1);
}