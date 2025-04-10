// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int times ;
//     cin >> times ;
//     int count = 1 ; 
//     while(times--){
//         vector<unsigned long long int> num ; 
//         int C ;
//         cin >> C ;
//         unsigned long long int n = 1 ;
//         while(C--){
//             int P , a  ;
//             cin >> P >> a ;
//             n *= pow(P,a);
//         }
//         for(int i = 1 ; i*i <= n ; i++ ){
//             if(n % i == 0 ){
//                 num.push_back(i);
//                 if (i * i != n ) num.push_back(n / i);
//             }
//         }
//         unsigned long long int ans = 0 ;
//         sort(num.begin(), num.end());
//         for(int i = 0 ; i < (int)num.size(); i++ ){ 
//             for(int j = i ; j < (int)num.size() ; j++ ){ 
//                 if( lcm(num[j],num[i]) == n   ){
//                     ans += (num[j]%1000000007 + num[i]%1000000007);
//                 }
//                 ans %= 1000000007;
//             }
//         }
//         cout << "Case "<< count++ <<": " << ans << endl;
//     }
// }
//when input is large enough , it will wrong.

#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long 
const int mod = 1000000007;

int32_t main(){
    int times ;
    cin >> times ;
    int count = 1;
    while(times--){
        int C ;
        cin >> C;
        vector<int> factor ;
        vector<int> power ; 
        int ans = 1; 
        int n = 1 ;
        while(C--){
            int P , a ;
            cin >> P >> a ;
            factor.push_back(P);
            power.push_back(a);
        }
        for(int i = 0 ; i < (int)factor.size() ; i++){
            int now = 1;    // 一開始設定 1 ， 每個factor的0次方都是1 
            int sigma = 1 ; // 直接先加好第0項
            for(int j = 1 ; j <= power[i] ; j++ ){
                now *= factor[i];
                now %= mod;
                sigma += now ;
                sigma %= mod;
            }
            // now 出來之後會變 p^k -> 然後sigma 要加上 k * p^k
            sigma += power[i] * now % mod ;
            ans *= sigma;   // 乘法原理
            ans %= mod;    
            n *= now;  
            n %= mod;
        }
        ans = (ans + n) % mod;
        cout << "Case " << count++ <<": " << ans << endl;
    }            
}


/*
    解題說明 : 
        此題給定一個n，把 n 因數分解後，找出lcm(p,q) = n ，且所有(p,q) 滿足 p <= q ，
        最後把所有的 (p,q) 組合都加起來，這裡使用乘法原理，把 n 質因數分解，變成 p1^k * p2^m.... = n，
        然後算出每個質數對於set的貢獻，先算只有一種質數的情況， n = 8 = 2^3 , 此時 p 可以是 1 , 2 , 4 , 8 ，但 q 只能是 8 ，
        所以(p,q)就是sigma(i=0~3)p^i + 3*8 = sigma(i=0~k)p^i + k * p^k + n ( n 是因為最後都會差一個 n ) ，
        最後推廣到多個質因數，乘法原理(sigma(i=0~k)p^i + k * p^k) + n 。
        例: n = 6 = 2^1 + 3^1 , 每一項是 1 , 2 , 2  = 5 | 1 , 3 , 3  = 7 -> 5 * 7 = 35 , 35 + 6 = 41 -> ans 
*/

//https://gdst.dev/posts/UVA-12546/index.html >> 參考資料
//Accepted online judge 