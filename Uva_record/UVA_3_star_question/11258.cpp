#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    int T ; 
    cin >> T;
    cin.ignore();
    while(T--){
        string input ;
        getline(cin,input);
        int DP[210] = {0}; // 算 0 ~ i-1 degit 最大值的情況
        for (int i = 0; i < input.size(); ++i) {    
            if (input[i] == '0') {  // 非 0 前導
                DP[i + 1] = max(DP[i + 1], DP[i]);
            } else {
                int sum = 0;
                for (int j = i; j < input.size(); ++j) {    // 算 digit i~j 的總和
                    sum = sum * 10 + (input[j] - '0'); 
                    if (sum > INT_MAX)  // 如果大於32-bit 的話就直接停掉
                        break;                               
                    DP[j + 1] = max(DP[j + 1], DP[i] + sum); // 更新這一個digit的和，要就是已經在裡面的(0~i)，或者是(0~i-1 + i~j )
                }
            }
        }
        cout << DP[input.size()] << endl; // 最後的答案就是 DP[input.size] -> 0~input.size的digit 
    }
}
// Accepted Uva 
/*
    解題說明 : 
        此題是要將數字拆分，找出小於32-bit的最大的數字是多少，做法是dp，有點像背包問題，   
        dp[i] 指的是處理到 i-1 字元的最大數字總和，那在迴圈過程中，我們處理 i ~ all 的數字總和，
        dp[j+1] 就是當 現在到第 j 個字元時，可以選擇原本的 0~j ，也可以選擇 i ~ 現在的sum(0~i-1 + i~j)， 
        也就是一個指標停在 i 的位置，另一個指標不斷的往後跑，去判斷哪時候加起來的數字最大，然後之後在 i 不同的時候遇到，就可以利用上一次計算的結果。
*/