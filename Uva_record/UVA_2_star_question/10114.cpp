#include<bits/stdc++.h>
using namespace std;

int main(){
    int duration , record ;
    double down_payment, amount ;
    while(cin >> duration >> down_payment >> amount >> record ){
        if(duration < 0 ){
            break;
        }
        double rate[duration + 1] = {};
        for(int i = 0 ; i < record ; i++ ){
            int month ;
            double r ;
            cin >> month >> r ;
            for(int j = month ; j <= duration ; j++ ){
                rate[j] = r ;
            }
        }
        double worth = amount + down_payment;
        double each_month = amount / duration ; 
        int ans= 0 ;  
        for(int i = 0 ; i <= duration ; i++ ){
            worth -= worth*rate[i];
            if( i != 0 ){
                amount -= each_month ;
            }   
            if( amount < worth ){
                ans = i ; 
                break;
            }
        }
        if(ans == 1 ){
            cout << ans << " month" << endl;
        }
        else{
            cout << ans << " months" << endl;
        }
    }
}