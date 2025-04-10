#include<bits/stdc++.h>
using namespace std;
#define int long long 

int power(int x , int y ){
    int sum = 1 ;
    while(y){
        if(y & 1) sum *= x ;
        x *= x ;
        y >>= 1 ;
    }
    return sum ; 
}


/*
    這題要我們解出一個 non-prime number ， 然後這個number 只被一個prime number整除 (也就是 prime_number的 n 次方 )
    Ex :  4 , 8 , 32 .... , 9 , 27 , 81 , .... , 16 , 64 , 256 ... 
    -> 所以我們一開始可以先建質數表，然後把質數表建出來之後，我們再建一個表，把所有再最大區間內的所有符合題目要求的數字放到陣列中(code內的array)
    再來呢，我們就從題目讀入區間，然後把array整個跑一次，計算有幾個數字在此區間內，就是最後的答案
 */
int32_t main(){
    int size = 1000000;
    vector<bool> map(size,false);
    vector<int> prime ;  // 建立質數表
    for(int i = 2 ; i < size; i++ ){
        if(!map[i]){
            prime.push_back(i);
            for(int j = i*i ; j < size ; j += i ){
                map[j] = true;
            }
        }
    }
    int l = 1 , h = 1000000000000;
    int * array = new int [80070];    // 建立 prime^k 次方的表
    int count = 0 ; 
    for(int i = 0 ; i < (int)prime.size() && prime[i]*prime[i] <= h ; i++ ){
        int h_loop = h ; 
        int k = 0 ;
        while(h_loop != 0 ){
            h_loop /= prime[i];
            k++;
        }
        for(int j = k ; j > 1 && power(prime[i],j) >= l ; j-- ){
            int num = power(prime[i] , j);
            if(num >= l && num <= h ){
                array[count++] = num ; 
            }
        }
    }
    int times ;
    cin >> times ;
    while(times--){
        int l_input , h_input ; 
        cin >> l_input >> h_input ;
        int ans = 0 ;
        for(int i = 0 ; i < count ; i++ ){
            if(array[i] <= h_input && array[i] >= l_input ){
                ans ++ ;
            }
        }
        cout << ans << endl;
    }
}