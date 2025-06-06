#include<bits/stdc++.h>
using namespace std;    
#define int long long 
int coins[] = {1 , 2 , 4 , 10 , 20 , 40 , 100 , 200 , 400 , 1000 , 2000};

int32_t main(){    
    vector<int> dp(6001,1);
    for(int i = 1 ; i < 11 ; i++ ){
        for(int j = coins[i] ; j <= 6000 ; j++ ){
            dp[j] += dp[j-coins[i]];
        }
    }
    double N ; 
    while(cin >> N && N != 0.0){
        int num = N * 20 ;
        cout << setw(6) << fixed << setprecision(2) << N ;
        cout << setw(17) << dp[num] << endl;
    }
}

// Accepted online judge.
/*
    解題說明: 這題屬於要 dp 出所有組合，而我的作法是先把全部的數字乘以20，這樣就不會有小數點，然後把每一種硬幣放進一個array裡面
    再來呢，如果現在是0.3元，在我程式裡，相當於6塊錢， 而6塊錢的組合就是 (6-2)塊錢的組合+(6-4)塊錢+所有都是1塊錢的組合 的組合，而如果這樣想的話，
    會重複算一個(4,2)的這個組合數，但如果寫在程式，可以解決這個問題。
    上方程式碼就是，6塊錢，我先把2塊錢拿出來，剩下4塊錢，但是4塊錢在跑用兩塊錢組合的起來的時候，只有(1,1,1,1),(1,1,2),(2,2) -> 不能用4塊(剛好與我們要的一樣，
    不會重複使用到4塊錢) ，所以這樣的結果就是在第一次迴圈遇到(6-2)塊錢的組合時，拿到的答案不是4，而是3，
    那再來，把4塊錢拿出來的時候，剩下2塊錢，也就只有(1,1),(2)，最後所有組合就是(2,1,1,1,1),(2,1,1,2),(2,2,2),(4,1,1),(4,2),(1,1,1,1,1,1,1,1)，剛好就
    找出所有的組合，所以最主要的是要從小的開始。
*/