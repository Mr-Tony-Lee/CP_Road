#include<bits/stdc++.h>
using namespace std;

int main(){
    string input1 , input2 ;
    int kase = 0 ; 
    while(getline(cin,input1) && getline(cin,input2)){
        vector<string> word1;
        vector<string> word2;
        string now = "";
        printf("%2d. ", ++kase);
        if(input1.size() == 0 || input2.size() == 0 ){
            cout << "Blank!" << endl;
            continue;
        }
        for(auto& ch : input1){
            if( isalnum(ch) ){
                now += ch ;
            }
            else{
                if(!now.empty()){
                    word1.push_back(now);
                    now.clear();
                }
            }
        }
        if(!now.empty()){
            word1.push_back(now);
            now.clear();
        }
        for(auto& ch : input2){
            if( isalnum(ch) ){
                now += ch ;
            }
            else{
                if(!now.empty()){
                    word2.push_back(now);
                    now.clear();
                }
            }
        }
        if(!now.empty()){
            word2.push_back(now);
            now.clear();
        }
        int m = word1.size() , n = word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 1 ; i <= m ; i++ ){
            for(int j = 1 ; j <= n ; j++ ){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1; 
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }        
        cout << "Length of longest match: " << dp[m][n] << endl;
    }
}
/*
This is a test.
test
Hello!

The document provides late-breaking information
late breaking.
*/