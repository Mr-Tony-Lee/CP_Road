#include<bits/stdc++.h>
using namespace std;
int N ;
vector<pair<int,int>> arr;

// 方法一：O(N^3) 區間 DP
void solve_DP(){
    vector<pair<int,int>> arr_dp;
    arr_dp.push_back({0,0});
    for(int i = 0 ; i < N ; i++ ){
        arr_dp.push_back(arr[i]);
    }
    arr_dp.push_back({INT32_MAX,INT32_MAX});
    int N_dp = arr_dp.size();
    
    // dp[i][j] 儲存：在 arr[i] 結束之後、arr[j] 開始之前，最多能選擇的活動數
    vector<vector<int>> dp(N_dp,vector<int>(N_dp,0));

    // 區間 DP 必須按照區間長度 L 遞增的順序計算
    // L 從 2 開始，因為長度 L=1 的區間 (i, i) 不包含任何活動，dp[i][i] 永遠是 0
    for(int L = 2 ; L <= N_dp ; L++){
        for(int i = 0; i <= N_dp - L ; i++ ){
            int j = i + L - 1;
            for(int k = i+1 ; k < j ; k++ ){
                if(arr_dp[i].second < arr_dp[k].first && arr_dp[k].second < arr_dp[j].first ){
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + 1 );
                }
            }
        }
    }

    cout << "DP(N^3) -> Max Activity: " << dp[0][N_dp-1] << endl;
}

// 方法二：O(N^2) 線性 DP
void solve_linear_dp(){
    // dp[i] 代表以「第 i 個實際活動」為結尾時，最多能選取的活動數
    // 至少包含自己，初始為 1
    vector<int> dp(N,1);
    int ans = 0 ;
    for(int i = 0 ; i < N ; i++ ){
        for(int j = 0 ; j < i ; j++ ){
            // j 檢查所有在 i 之前的活動
            if(arr[j].second < arr[i].first ){
                // 嘗試把每個 j 接進去
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ans = max(ans,dp[i]);
    }
    cout << "DP(N^2) -> Max Activity: " << ans << endl; 
}

void solve_greedy(){
    int last_end = 0 ; 
    int ans = 0 ; 
    for(int i = 0 ; i < N ; i++ ){
        if(arr[i].first > last_end ){
            last_end = arr[i].second ;
            ans++;
        }
    }
    cout << "Greedy -> Max Activity: " << ans << endl;
}

bool cmp(pair<int,int> a , pair<int,int> b ){
    if(a.second == b.second)
        return a.first < b.first ;
    return a.second < b.second;
}

int main(){
    ifstream in ;
    in.open("input.txt");
    in >> N ; 
    int s , f ;
    for(int i = 0 ; i < N ; i++ ){
        in >> s >> f ;
        arr.push_back({s,f});
    }
    sort(arr.begin(), arr.end() , cmp);
    in.close();
    solve_DP();
    solve_linear_dp();
    solve_greedy();
    
}