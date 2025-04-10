#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    double t ;
    double dp[31] ; // dp[i] 表示答對i題後的最大期望獎金
    
    while(cin >> n >> t ){
        if(n == t && n == 0 ) break;
        dp[n] = 1 << n ;    // dp[n] = 2^ n ， 因為答對 n 題後就不能往後了，最大期望獎金就是 2 ^ n
        for(int i = n-1 ; i >= 0 ; i--){
            double p0 = max(t, ((double)(1 << i) / dp[i+1]));   
            // 因為每一題的最大期望獎金就是 max(2^n , p * d[i+1]) ， 所以假定 p0 是 max(t,2^n / d[i+1]) (因為 p >= t )
            // 這樣就可以討論 當 p < p0 時 ， 2^n > p*d[i+1] -> 不回答比較好 
            // 當 p >= p0 時 ， 回答比較好， 期望值就是 機率平均(平均分布) * d[i+1] -> (1+p0)/2 * d[i+1] >> (1+p0)/2 是因為 p 可以是 p0 ~ 1 
            // 那麼 在第一種情況下 p 的實際範圍是 [t,p0) >> p1 = (p0-t)/1-t (平均分布) , 然後第二種期況的 p 當然就是 1-p1
            double p1 = (p0-t)/(1-t); 
            dp[i] = (1 << i) * p1 + ((1+p0)/2) * dp[i+1] * (1-p1);
        }
        cout << fixed << setprecision(3) << dp[0] << endl;
    }
}

