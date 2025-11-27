#include<bits/stdc++.h>
using namespace std;

int main(){
    string input1;
    string input2;
    int kase = 0 ;  
    while(getline(cin,input1)){
        if(input1 == "#"){
            break;
        }
        getline(cin,input2);
        int n = input1.size();
        int m = input2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1 ; i <= n ; i++ ){
            for(int j = 1 ; j <= m ; j++ ){
                if(input1[i-1] == input2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1; // 字符相同，LCS長度加1
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // 取較長的LCS長度
                }
            }
        }
        cout << "Case #" << ++kase << ": you can visit at most " << dp[n][m] << " cities." << endl;
    }
}