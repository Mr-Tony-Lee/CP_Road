#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main() {
    int number;
    while (cin >> number && number) {
        int dp[31][3] = {0};
        dp[0][0] = 1;
        for (int i = 1; i <= number; i++) {
            dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];    // 上一層合法的全部最後填L
            dp[i][1] = dp[i-1][0];  // 上一層最後沒有U，這層填U才會是1個U
            dp[i][2] = dp[i-1][1];  // 上一層最後是U這層填U才會是2個U
        }
        cout << (1 << number) - dp[number][0] - dp[number][1] - dp[number][2] << endl;  // 非法的組合 就是 (全部的組合)-(合法的組合)
    }
    return 0;
}

//Online judge Accepted.
/*
    解題說明 : 
        我們要求出不合法的組合數(三個U相鄰的組合)，所以這題使用DP解題，使用所有的組合 - 合法的組合，dp[i][n]代表當現在有i個桶子，最上面是 n 個U
        那每一層都可以選擇放 U 或放 L ， 可以在任何地方放L ，但U只能放在最上面1個U或沒有U的情況(所以U最多是2個)，
        那因為任何地方都可以放L ，dp[i][0](上面沒有代表現在放L) = dp[i-1][0] + dp[i-1][1] + dp[i-1][2]，
        然後上面1個U的情況就是原本的最上面是L，dp[i][1] = dp[i-1][0]，
        上面兩個U的情況就是原地的最上面是1個U，dp[i][2] = dp[i-1][1]
        最後非法就是 2^i - dp[i][0]- dp[i][1] - dp[i][2]
*/