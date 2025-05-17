#include<bits/stdc++.h>
using namespace std;

#define int long long 

int Extend_Euclidean_algorithm(int A , int B , int& X , int& Y ){
    if (B == 0 ){
        X = 1 , Y = 0 ;
        return A ;
    }
    int d = Extend_Euclidean_algorithm(B , A%B, Y , X );
    Y -= A / B * X ; 
    return d ;
}

int32_t main(){
    int A , B ;
    while(cin >> A >> B ){
        int X , Y ; 
        int D = Extend_Euclidean_algorithm(A,B, X , Y);
        // AX + BY = D
        cout << X << " " << Y << " " << D << endl;
    }
}
// 參考資料 : https://zh.wikipedia.org/wiki/%E6%89%A9%E5%B1%95%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97%E7%AE%97%E6%B3%95
// https://yuihuang.com/zj-e603/
// 每一層 X , Y 交換位置
// 交換後 Y -= A * B / X 
