#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> prime;
    int N = 40000;
    vector<bool> table(N,false);
    prime.push_back(2);
    for(int i = 3 ; i < N ; i+=2){
        if(!table[i]){
            table[i] = true;
            prime.push_back(i);
            for(int j = 2*i ; j < N ; j += i){
                table[j] = true;
            }
        }
    }
    int n ;
    while(cin >> n , n ){
        int ans = 0 ;
        // i 可以理解為當前圈子裡的人數。
        for(int i = 2 ; i <= n ; i++ ){
            ans = (ans + prime[n-i]) % i ; // 模擬被淘汰的人的位置
            // 這個計算更新了在當前 i 個人中，下一個要被“淘汰”的人的相對位置（從 0 開始計數）。
        }
        cout << ans + 1 << endl;    // 到最後倖存的就是最後一個被淘汰的下一個人
    }
}

// 1 2 3 4 5 6
// 1 3 4 5 6
// 1 3 4 6
// 1 3 4
// 3 4
// 4
/*
當有 n 個人時，第一輪會淘汰掉第 k 個人。
剩下 n−1 個人，他們形成一個新的圈，但起始位置發生了變化。
我們可以將這個新的問題看作一個規模為 n−1 的約瑟夫問題，然後將其結果轉換回原始圈中的位置。
*/
