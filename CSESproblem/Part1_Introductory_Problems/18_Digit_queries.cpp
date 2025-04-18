#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
using ll = unsigned long long ;

ll power(ll a , ll b ){
    ll ans = 1 ;
    while(b > 0) {
        if(b & 1 ) ans = ans * a ;
        a *= a ;
        b >>= 1 ;
    } 
    return ans ;
}

int main(){
    int q ;
    cin >> q ;
    vector<ll> bound;
    ll now = 10;
    int digit = 1 ;
    bound.push_back(1);
    //找出每個位數的邊界 
    //個位數的 1~10 (不含10)
    //雙位數的 10 ~ 190 
    // ............... 
    while(now <= 1e18){
        bound.push_back(now);
        now +=  ( 9 * power(10,digit)) * (digit+1);
        digit++;
    }
    bound.push_back(1e18);
    while(q--){
        ll k ;
        cin >> k ;
        ll l ;
        ll i ;

        //抓出上界 and 下界
        for(i = 0 ; i < (ll)bound.size()-1 ; i++ ){
            if(bound[i] <= k && k < bound[i+1] ){
                l = bound[i] ;
                break;
            }
        }
        // 算出K在的number是什麼
        ll number = ll((k-l)/(i+1)) + power(10,i);
        // 算出這個K在number中的位置
        ll pos = (k-l) % (i+1) ;
        vector<int> number_digit;
        for(int i = 0 ; number > 0  ; i++ ){
            number_digit.push_back(number%10);
            number /= 10;
        }
        cout << number_digit[number_digit.size()-pos-1] << endl;
    }
}
