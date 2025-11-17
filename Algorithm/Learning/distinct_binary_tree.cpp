#include<bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main(){
    cin.tie(0) ; cout.tie(0) ; ios::sync_with_stdio(0);
    bool prime_map[1000] = {} ;
    vector<int> prime;
    for(int i = 2 ; i <= 1000 ; i++ ){
        if(!prime_map[i]){
            prime.push_back(i);
            for(int j = 2*i ; j <= 1000 ; j += i ){
                prime_map[j] = true ;
            }
        }
    }
    // 複雜度 篩法的複雜度是 O(n log n )
    // 下方的話 找出 n+2 ~ 2n 的 fac O(n/2 * n) = O(n^2)
    // 找出 n! -> O(n^2)
    // 總複雜度 O(n^2)
    
    for(int n = 1 ; n <= 300 ; n++ ) {
        // 2n! / (n!*n!*(n+1)) -> 這是不同形狀的binary tree 個數 

        // 那可以使用 質因數的除法
        // 找出 n+2 ~ 2n 乘起來的質因數
        // 找出 2~ n 乘幾來的質因數
        // 最後因為兩個一定能相除，使用map扣掉

        map<int,int> factor ; 
        for(int i = n+2 ; i <= 2*n ; i++ ){
            int copy = i ; 
            for(int j = 0 ; j < prime.size() ; j++ ){
                while ( copy % prime[j] == 0 && copy != 0 ){
                    copy /= prime[j] ;
                    factor[prime[j]]++;
                }
                if( copy == 0 ) break;
            }
        }
        map<int,int> factor_n ;
        for(int i = 2 ; i <= n ; i++ ){
            int copy = i ;
            for(int j = 0 ; j < prime.size() ; j++ ){
                while(copy % prime[j] == 0 && copy != 0 ){
                    copy /= prime[j];
                    factor_n[prime[j]]++;
                }
            }
        }
        for(auto& iter:factor_n){
            factor[iter.first] -= iter.second ;
        }
        int ans[5000] = {}; ans[0] = 1 ;
        int ans_size = 1 ;
        for(auto& iter:factor){
            for(int i = 0 ; i < iter.second ; i++ ){
                int carry = 0 ; 
                for(int j = 0 ; j < ans_size ; j++ ){
                    int new_digit = ans[j] * iter.first + carry ; 
                    carry = new_digit / 10 ; 
                    ans[j] = new_digit % 10 ; 
                }
                while(carry > 0 ){
                    ans[ans_size++] = carry % 10 ;
                    carry /= 10 ;
                }
            }
        }
        cout << "n = " << n << ", number is : ";
        for(int i = ans_size-1 ; i >= 0 ; i-- ){
            cout << ans[i] ;
        }
        cout << endl;
    }
}