#include<bits/stdc++.h>
using namespace std;
#define int long long 

int solve(int K , int row ){
    if (row == 0 ){ 
        return 0;
    }

    if(K == 0 ){
        return 1 ;
    }
    
    if(row <= pow(2,K-1)){
        return 2 * solve(K-1 , row);
    }
    else{
        return solve( K-1 , row-pow(2 , K-1)) + 2 * pow(3,K-1) ;
    }
}

int32_t main(){
    int T;
    cin >> T;
    int count = 1 ;
    while(T--){
        int K , A , B ; 
        cin >> K >> A >> B ;
        cout << "Case " << count << ": " << solve(K,B) - solve(K,A-1) << endl;  
        count++;
    }
}
/*
    解題說明 : 
        第K個hours的第A~B排的紅色球數量，那觀察之後，可以發現有規律，我們可以用遞迴去實作
        如果 row <= 2^(K-1) ， 可以發現紅色球的數量就是 兩倍的K-1 hours 的數量，
        然後如果 row > 2^(K-1)，那就是 兩倍全部的 K-1 hours + K-1 hours 時的 row = row - 2^K-1，
        而兩倍全部的 K-1 hours 就是 2 * 3^(K-1)，最後就能寫出遞迴式
*/
// Accepted Uva